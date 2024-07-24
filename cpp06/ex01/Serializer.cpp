# include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::~Serializer() {
}

Serializer::Serializer(const Serializer &other) {
	if (this != &other) {
		*this = other;
	}
}

Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
	return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data* Serializer::deserialize(uintptr_t raw) {
	return ( reinterpret_cast<Data *>(raw) );
}

Base &a = dym_cast<Base>(b);
Base *b = dym_cast<Base>(c);