#include <thread>
#include "async_server.h"

namespace async {

    using handle_t = void *;

    handle_t connect(std::string port, std::size_t bulk);
    void receive(handle_t handle, const char *data, std::size_t size);
    void disconnect(handle_t handle);

}

int main(int, char *[]) {
    std::size_t bulk = 3;
    short port = 8031;
    boost::asio::io_service io_service;

    AsyncBulkServer server(port, bulk, io_service);
    io_service.run();

    return 0;
}