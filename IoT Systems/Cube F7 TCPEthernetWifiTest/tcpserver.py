import socket
from threading import Thread

def handle_client(client_socket, address):
    print(f"New connection from {address}")
    while True:
        try:
            data = client_socket.recv(1024)  # Receive up to 1024 bytes
            if not data:
                break
            print(f"Received from {address}: {data.decode('utf-8')}")
            response = "Response to " + data.decode('utf-8') + "\r\n"
            client_socket.sendall(response.encode())
        except ConnectionResetError:
            print(f"Connection with {address} lost.")
            break
    client_socket.close()
    print(f"Connection closed with {address}")

def start_server(host='0.0.0.0', port=3100):
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((host, port))
    server.listen(5)
    print(f"Server started on {host}:{port}")

    while True:
        client_socket, address = server.accept()
        client_thread = Thread(target=handle_client, args=(client_socket, address))
        client_thread.start()

if __name__ == "__main__":
    try:
        start_server()
    except KeyboardInterrupt:
        print("\nShutting down the server...")