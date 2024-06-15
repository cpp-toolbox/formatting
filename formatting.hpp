#include "../interaction/multiplayer_physics/physics.hpp"
#include "../networked_input_snapshot/networked_input_snapshot.hpp"
#include "spdlog/fmt/ostr.h" // must be included
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"

std::ostream &operator<<(std::ostream &os, const Physics &physics);
std::ostream &operator<<(std::ostream &os, const NetworkedInputSnapshot &snapshot);
std::ostream &operator<<(std::ostream &os, const NetworkedCharacterData &data);
std::ostream &operator<<(std::ostream &os, const JPH::Vec3 &vector);

// fmt v10 and above requires `fmt::formatter<T>` extends
// `fmt::ostream_formatter`. See: https://github.com/fmtlib/fmt/issues/3318
template <> struct fmt::formatter<Physics> : fmt::ostream_formatter {};
template <> struct fmt::formatter<NetworkedInputSnapshot> : fmt::ostream_formatter {};
template <> struct fmt::formatter<NetworkedCharacterData> : fmt::ostream_formatter {};
template <> struct fmt::formatter<JPH::Vec3> : fmt::ostream_formatter {};
