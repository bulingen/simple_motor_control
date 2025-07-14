#pragma once

#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "hardware_interface/handle.hpp"
#include "rclcpp/macros.hpp"
#include <vector>
#include <string>

namespace simple_motor_control
{

class SimpleMotorHardware : public hardware_interface::SystemInterface
{
public:
  RCLCPP_SHARED_PTR_DEFINITIONS(SimpleMotorHardware)

  hardware_interface::CallbackReturn on_init(const hardware_interface::HardwareInfo & info) override;

  std::vector<hardware_interface::StateInterface> export_state_interfaces() override;

  std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

  hardware_interface::CallbackReturn on_activate(const rclcpp_lifecycle::State &) override;

  hardware_interface::CallbackReturn on_deactivate(const rclcpp_lifecycle::State &) override;

  hardware_interface::return_type read(const rclcpp::Time &, const rclcpp::Duration &) override;

  hardware_interface::return_type write(const rclcpp::Time &, const rclcpp::Duration &) override;

private:
  double motor_velocity_command_ = 0.0;
  double motor_velocity_state_ = 0.0;
};

}  // namespace simple_motor_control