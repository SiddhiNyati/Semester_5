import socket

class UDPClient:
    def __init__(self, total_servers=5):
        self.total_servers = total_servers
        self.partition_sums = [0] * total_servers
        self.received_count = 0
        self.server_ports = [5000 + i for i in range(total_servers)]
    
    def send_request(self, partition, n, t):
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        start_index = partition * (n // self.total_servers)
        end_index = start_index + (n // self.total_servers) - 1
        
        request_message = f"Request,1,{partition},{start_index},{end_index},{n},{t}"
        client_socket.sendto(request_message.encode(), ('localhost', self.server_ports[partition]))
        print(f"Request sent for partition {partition} to server on port {self.server_ports[partition]}")
        
        return client_socket

    def handle_response(self, client_socket):
        data, _ = client_socket.recvfrom(1024)
        response = data.decode().split(',')
        partition_index = int(response[2])
        partition_sum = float(response[6])
        
        self.partition_sums[partition_index] = partition_sum
        self.received_count += 1
        
        print(f"Received partition {partition_index} sum: {partition_sum}")
        print(f"Current partition sums: {self.partition_sums}")

        if self.received_count == self.total_servers:
            total_sum = sum(self.partition_sums)
            print(f"Final total sum: {total_sum}")

    def compute_result(self, n, t):
        for partition in range(self.total_servers):
            client_socket = self.send_request(partition, n, t)
            self.handle_response(client_socket)
            client_socket.close()

if __name__ == "__main__":
    try:
        n = int(input("Enter the total number of terms (N): "))
        t = int(input("Enter the exponent value (T): "))
        
        if n <= 0 or n % 5 != 0:
            raise ValueError("N must be a positive integer and divisible by 5.")
        
        udp_client = UDPClient()
        udp_client.compute_result(n, t)
    except ValueError as ve:
        print(f"Input Error: {ve}")
    except Exception as e:
        print(f"An error occurred: {e}")