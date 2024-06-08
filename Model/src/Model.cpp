#include "Model.h"

Model::Model() {}

Model& Model::getInstance() {
    static Model m = Model();
    return m;
}
