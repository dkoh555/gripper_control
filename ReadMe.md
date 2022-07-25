# 1. Introduction
This package works with the EZgripper by SAKE Robotics (https://sakerobotics.com/support/) and is to be used in conjuction with the arm_control repo

# 2. Installation
Follow the installation instructions for the EZgripper Python drivers and libraries (https://github.com/SAKErobotics/libezgripper/tree/ubuntu-20.04), make sure to select the branch ubuntu-20.04 because it is not the default one.

# 3. Potential Error
Once everything is installed, you may still face issues connecting with the gripper - even after trying the suggested fixes by the EZgripper Python repo.

This error may look like:

    [Errno 13] Permission denied: '/dev/ttyUSB0'

In that case, follow the instruction in this link (https://sudomod.com/forum/viewtopic.php?t=6075) and it should work as intended.