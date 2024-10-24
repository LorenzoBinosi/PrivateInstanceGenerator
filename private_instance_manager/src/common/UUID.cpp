#include "common/UUID.hpp"

// Default constructor generates a new random UUID
UUID::UUID() : uuid_(boost::uuids::random_generator()()) {}

// Constructor that accepts an existing boost::uuids::uuid
UUID::UUID(const boost::uuids::uuid& uuid) : uuid_(uuid) {}

// Constructor that accepts a string representation of a UUID
UUID::UUID(const std::string& uuid_str) {
    try {
        // Create a string generator and parse the string to UUID
        boost::uuids::string_generator gen;
        uuid_ = gen(uuid_str);
    } catch (const std::exception& e) {
        throw std::invalid_argument("Invalid UUID string format: " + uuid_str);
    }
}

// Return the UUID as a string
std::string UUID::toString() const {
    return boost::uuids::to_string(uuid_);
}

// Return the raw boost::uuids::uuid object
boost::uuids::uuid UUID::getUUID() const {
    return uuid_;
}

// Equality operator
bool UUID::operator==(const UUID& other) const {
    return uuid_ == other.uuid_;
}

// Inequality operator
bool UUID::operator!=(const UUID& other) const {
    return uuid_ != other.uuid_;
}
