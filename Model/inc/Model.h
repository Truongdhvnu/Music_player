#pragma once
#include <string>
#include <vector>
#include "MediaManager.h"

using namespace std;

class Model {
    Model();
public:
    MediaManager mediaManager;
    static Model& getInstance();
};