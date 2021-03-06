#pragma once

#include <AP_Arming/AP_Arming.h>
#include <AC_Fence/AC_Fence.h>

/*
  a rover-specific arming class
 */
class AP_Arming_Rover : public AP_Arming
{
public:

    AP_Arming_Rover() : AP_Arming() { }

    /* Do not allow copies */
    AP_Arming_Rover(const AP_Arming_Rover &other) = delete;
    AP_Arming_Rover &operator=(const AP_Arming_Rover&) = delete;

    bool pre_arm_checks(bool report) override;
    bool arm_checks(AP_Arming::Method method) override;
    bool pre_arm_rc_checks(const bool display_failure);
    bool gps_checks(bool display_failure) override;

    bool disarm() override;
    bool arm(AP_Arming::Method method, bool do_arming_checks=true) override;

    void update_soft_armed();

protected:
    bool oa_check(bool report);

private:

    void change_arm_state(void);
};
