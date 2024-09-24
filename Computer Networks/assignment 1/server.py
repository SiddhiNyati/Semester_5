import socket
import sys

def compute_partition_sum(start, end, t):
    total_sum = sum(i ** t for i in range(start, end + 1))
    return total_sum

def start_server(port):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(('localhost', port))
    print(f"Server running on port {port} and waiting for client requests...")

    while True:
        try:
            #message from client
            data, client_address = server_socket.recvfrom(1024)
            print(f"Request received from {client_address}: {data.decode()}")

            message_parts = data.decode().split(',')
            partition = int(message_parts[2])
            start = int(message_parts[3])
            end = int(message_parts[4])
            n = int(message_parts[5])
            t = int(message_parts[6])

            partition_sum = compute_partition_sum(start, end, t)
            print(f"Computed sum for partition {partition}: {partition_sum}")

            response = f"Reply,1,{partition},{end - start + 1},{n},{t},{partition_sum}"
            server_socket.sendto(response.encode(), client_address)
            print(f"Response sent to {client_address}: {response}")

        except Exception as e:
            print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 server.py <port_number>")
        sys.exit(1)
    
    port_number = int(sys.argv[1])

    start_server(port_number)