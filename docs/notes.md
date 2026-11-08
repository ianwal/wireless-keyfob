# Notes

The microcontroller, which controls the keyfob, runs a Bluetooth Low Energy server which periodically scans
for a GATT to lock/unlock the car.

The GATT is broadcast from some Bluetooth Low Energy client, e.g., a phone.
