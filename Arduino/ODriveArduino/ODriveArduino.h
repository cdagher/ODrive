
#ifndef ODriveArduino_h
#define ODriveArduino_h

#include "Arduino.h"
#include "ODriveEnums.h"

class ODriveArduino {
public:
    ODriveArduino(Stream& serial);

    // Commands
    void SetPosition(int motor_number, float position);
    void SetPosition(int motor_number, float position, float velocity_feedforward);
    void SetPosition(int motor_number, float position, float velocity_feedforward, float current_feedforward);
    void SetVelocity(int motor_number, float velocity);
    void SetVelocity(int motor_number, float velocity, float current_feedforward);
    void SetCurrent(int motor_number, float current);
    void setTorque(int motor_number, float torque);
    void TrapezoidalMove(int motor_number, float position);

    int readODriveErrors();
    int readMotorErrors(int motor_number);
    int readAxisErrors(int axis_number);
    int readEncoderErrors(int encoder_number);
    int readControllerErrors(int controller_number);

    void reboot();
    void clearErrors();
    // Getters
    float GetVelocity(int motor_number);
    float GetPosition(int motor_number);
    // General params
    float readVoltage();
    float readFloat();
    int32_t readInt();

    // State helper
    bool run_state(int axis, int requested_state, bool wait_for_idle, float timeout = 10.0f);
private:
    String readString();

    Stream& serial_;
};

#endif //ODriveArduino_h
