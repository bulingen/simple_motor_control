#include "simple_motor_control/simple_motor_hardware.hpp"
#include "pluginlib/class_list_macros.hpp"

namespace simple_motor_control
{

hardware_interface::CallbackReturn SimpleMotorHardware::on_init(const hardware_interface::HardwareInfo &)
{
  return hardware_interface::CallbackReturn::SUCCESS;
}

std::vector<hardware_interface::StateInterface> SimpleMotorHardware::export_state_interfaces()
{
  std::vector<hardware_interface::StateInterface> state_interfaces;
  state_interfaces.emplace_back(
    hardware_interface::StateInterface("motor_joint", "velocity", &motor_velocity_state_)
  );
  return state_interfaces;
}

std::vector<hardware_interface::CommandInterface> SimpleMotorHardware::export_command_interfaces()
{
  std::vector<hardware_interface::CommandInterface> command_interfaces;
  command_interfaces.emplace_back(
    hardware_interface::CommandInterface("motor_joint", "velocity", &motor_velocity_command_)
  );
  return command_interfaces;
}

hardware_interface::CallbackReturn SimpleMotorHardware::on_activate(const rclcpp_lifecycle::State &)
{
  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn SimpleMotorHardware::on_deactivate(const rclcpp_lifecycle::State &)
{
  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::return_type SimpleMotorHardware::read(const rclcpp::Time &, const rclcpp::Duration &)
{
  // Fake feedback: just echo the command as the state
  motor_velocity_state_ = motor_velocity_command_;
  return hardware_interface::return_type::OK;
}

hardware_interface::return_type SimpleMotorHardware::write(const rclcpp::Time &, const rclcpp::Duration &)
{
  // TODO: Send motor_velocity_command_ to hardware here
  return hardware_interface::return_type::OK;
}

}  // namespace simple_motor_control

PLUGINLIB_EXPORT_CLASS(simple_motor_control::SimpleMotorHardware, hardware_interface::SystemInterface)