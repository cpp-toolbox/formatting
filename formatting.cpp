#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h" // must be included
#include "spdlog/sinks/stdout_sinks.h"

#include "formatting.hpp"

// Overload the << operator for the Physics class
std::ostream &operator<<(std::ostream &os, const Physics &physics) {
    os << "vvv Physics State vvv"
       << "\n";
    for (const auto &pair : physics.client_id_to_physics_character) {
        uint64_t client_id = pair.first;
        JPH::Ref<JPH::CharacterVirtual> character = pair.second;

        // Get position and velocity
        JPH::Vec3 position = character->GetPosition();
        JPH::Vec3 velocity = character->GetLinearVelocity();

        os << "Client ID: " << client_id << "\n";
        os << "Position: (" << position.GetX() << ", " << position.GetY() << ", " << position.GetZ() << ")\n";
        os << "Velocity: (" << velocity.GetX() << ", " << velocity.GetY() << ", " << velocity.GetZ() << ")\n";
    }
    return os;
}
// Overload the << operator for the NetworkedInputSnapshot class
std::ostream &operator<<(std::ostream &os, const NetworkedInputSnapshot &snapshot) {
    os << "Client ID: " << snapshot.client_id << "\n";
    os << "Client Input History Insertion Time (epoch ms): " << snapshot.client_input_history_insertion_time_epoch_ms
       << "\n";
    os << "Time Delta Used For Client-Side Processing (ms): " << snapshot.time_delta_used_for_client_side_processing_ms
       << "\n";
    os << " | L: " << (snapshot.left_pressed ? "1" : "0");
    os << " | R: " << (snapshot.right_pressed ? "1" : "0");
    os << " | F: " << (snapshot.forward_pressed ? "1" : "0");
    os << " | B: " << (snapshot.backward_pressed ? "1" : "0");
    os << " | J: " << (snapshot.jump_pressed ? "1" : "0") << "\n";
    os << "Mouse Position: (" << snapshot.mouse_position_x << ", " << snapshot.mouse_position_y << ")\n";
    return os;
}

std::ostream &operator<<(std::ostream &os, const NetworkedCharacterData &data) {
    os << "Client ID: " << data.client_id << ",\n"
       << "Client Input History Insertion Time (epoch ms): " << data.cihtems_of_last_server_processed_input_snapshot
       << ",\n"
       << "Position: (" << data.character_x_position << ", " << data.character_y_position << ", "
       << data.character_z_position << "),\n"
       << "Velocity: (" << data.character_x_velocity << ", " << data.character_y_velocity << ", "
       << data.character_z_velocity << "),\n"
       << "Camera Yaw Angle: " << data.camera_yaw_angle << ",\n"
       << "Camera Pitch Angle: " << data.camera_pitch_angle;
    return os;
}
