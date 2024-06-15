#pragma once

// Next briefs added for set logger statuses, not explaining logger work!
/// @brief Type of messages for logger
enum MessageType
{
    /// @brief For info, warn and error messages (default)
    INFO,
    /// @brief For warn and error messages
    WARN,
    /// @brief For only error messages
    ERROR,
    /// @brief For disable logger
    NONE
};