//
// Created by Xingqi Tang on 2018/7/5.
//

#include "TestController.h"
#include "vhdController.h"

using namespace std;

TestController::TestController() {
    //
}

TestController::~TestController() {
    //
}

bool TestController::testVhd() {
    vhdController vhdController_test;
    perror(vhdController_test.create_vhd() ? "[ok]vhd_create_success." : "[err]vhd_create_failed.");
    //perror(vhdController_test.del_vhd() ? "[ok]vhd_del_success." : "[err]vhd_del_failed.");
    return true;
}

bool TestController::testvhdController(vhdController &_vhd_) {
    if (!_vhd_.Exists_vhd()) {
        cout << "create vhd" << endl;
        if (_vhd_.create_vhd())
            cout << "the vhd has been create" << endl;
        else
            cout << "create error" << endl;
    }
    if (_vhd_.load_vhd())
        cout << "vhd load done" << endl;
    else
        cout << "vhd load error" << endl;
    char wbuff[BLOCK_SIZE];
    memset(wbuff, 0, BLOCK_SIZE);
    strcpy(wbuff, "test0");
    _vhd_.write_vhd(wbuff, 0);
    strcpy(wbuff, "test1");
    _vhd_.write_vhd(wbuff, 1);
    char rdbuff[BLOCK_SIZE];
    _vhd_.read_vhd(rdbuff, 0);
    string rdbuff_s(rdbuff);
    if (rdbuff_s == "test0") {
        _vhd_.read_vhd(rdbuff, 1);
        string rdbuff_s(rdbuff);
        if (rdbuff_s == "test1")
            return true;
        else {
            cout << "test fails" << endl;
            return false;
        }
    } else {
        cout << "test fails 2" << endl;
        return false;
    }
}