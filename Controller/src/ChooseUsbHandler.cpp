#include "ChooseUsbHandler.h"

ChooseUsbHandler::ChooseUsbHandler() : model(Model::getInstance()) {
    callback = Controller::changeHandler;
}

ChooseUsbHandler* ChooseUsbHandler::getInstance() {
    static ChooseUsbHandler instance = ChooseUsbHandler();
    return &instance;
}

void ChooseUsbHandler::onStart(void* passData) {
    usbMonitor.setUserPath();
    usbPath = usbMonitor.getSubdirectories(usbMonitor.getUserPathValue());
    this->view.display(usbPath);
}

void ChooseUsbHandler::handle(std::string command) {
    std::cout << "Vao handle cua chose USB" << std::endl;
    try {
        int cmdIndex = std::stoi(command);
        if (cmdIndex <= (int)usbPath.size() && cmdIndex > 0) {
            this->model.media_manager.setActiveLibrary();
            Library* lib = this->model.media_manager.getActiveLibrary();
            std::string path_dir = usbPath[cmdIndex - 1];
            (*lib).getSongFromPath(path_dir);
            std::cout << "Using path" << path_dir << std::endl;
            change_handler(SongListHandler::getInstance());
        } else {
            std::cout << "No actions or Invalid command in chosing usb" << std::endl;
        }
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void ChooseUsbHandler::leavePage() {
    // Định nghĩa hàm leavePage nếu cần, hoặc để trống nếu chưa sử dụng.
}
