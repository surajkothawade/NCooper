/*
    Copyright IdeaLounge.io 2018
 */

#include "ai/nn/activation.hpp"

namespace ncooper {
namespace ai {
namespace nn {

Activation::Activation() {
	std::cout << "No activation name has been specified." << std::endl;
	this->activationName = "relu";
	std::cout << "Default activation relu chosen" << std::endl;
}

Activation::Activation(std::string activationName) {
	if (std::find(this->activationsList.begin(), this->activationsList.end(), activationName) != this->activationsList.end()) {
		this->activationName = activationName;
	} else {
		this->activationName = "relu";
		std::cout << "Default activation relu chosen" << std::endl;
	}
}


// Use enum and replace these if-else-if statements
float Activation::computeActivation(float z) {
	if (this->activationName == "identity") {
		return identity(z);
	} else if (this->activationName == "sigmoid") {
		return sigmoid(z);
	} else if (this->activationName == "tanh") {
		return this->tanh(z);
	} else if (this->activationName == "relu") {
		return this->relu(z);
	} else if (this->activationName == "leakyRelu") {
		return this->leakyRelu(z);
	}
}

float Activation::identity(float z) {
	return (z);
}


float Activation::sigmoid(float z) {
	return (1 / (1 + std::exp(-z)));
}


float Activation::tanh(float z) {
	return ((std::exp(z) - std::exp(-z)) / ((std::exp(z) + std::exp(-z))));
}


float Activation::relu(float z) {
	return ((z >= 0) ? z : 0.0);
}


float Activation::leakyRelu(float z) {
	return ((z >= 0) ? z : (0.01 * z));
}
}
}
}
