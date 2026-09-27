#include <iostream>
#include <string>
using namespace std;

class SmartDevice
{
protected:
    string deviceId;
    string location;
    string status;
    string lastUpdated;

public:
    SmartDevice(string id, string loc, string stat, string time)
    {
        deviceId = id;
        location = loc;
        status = stat;
        lastUpdated = time;
    }

    void switchOn()
    {
        status = "ON";
        lastUpdated = "10:30 AM";
        cout << deviceId << " switched ON." << endl;
    }

    void switchOff()
    {
        status = "OFF";
        lastUpdated = "10:35 AM";
        cout << deviceId << " switched OFF." << endl;
    }

    void changeStatus(string newStatus)
    {
        status = newStatus;
        lastUpdated = "10:40 AM";
    }

    virtual void displayInfo() const
    {
        cout << "Device ID: " << deviceId << endl;
        cout << "Location: " << location << endl;
        cout << "Status: " << status << endl;
        cout << "Last Updated: " << lastUpdated << endl;
    }

    virtual ~SmartDevice() {}
};

class Light : public SmartDevice
{
public:
    Light(string id, string loc, string stat, string time)
        : SmartDevice(id, loc, stat, time) {}

    void displayInfo() const override
    {
        cout << "\n--- Light ---" << endl;
        SmartDevice::displayInfo();
    }
};

class Thermostat : public SmartDevice
{
public:
    Thermostat(string id, string loc, string stat, string time)
        : SmartDevice(id, loc, stat, time) {}

    void displayInfo() const override
    {
        cout << "\n--- Thermostat ---" << endl;
        SmartDevice::displayInfo();
    }
};

class Camera : public SmartDevice
{
public:
    Camera(string id, string loc, string stat, string time)
        : SmartDevice(id, loc, stat, time) {}

    void displayInfo() const override
    {
        cout << "\n--- Camera ---" << endl;
        SmartDevice::displayInfo();
    }
};

class DoorLock : public SmartDevice
{
public:
    DoorLock(string id, string loc, string stat, string time)
        : SmartDevice(id, loc, stat, time) {}

    void displayInfo() const override
    {
        cout << "\n--- Door Lock ---" << endl;
        SmartDevice::displayInfo();
    }
};

int main()
{
    Light light("L001", "Living Room", "OFF", "10:00 AM");
    Thermostat thermostat("T001", "Bedroom", "OFF", "10:05 AM");
    Camera camera("C001", "Main Door", "OFF", "10:10 AM");
    DoorLock doorLock("D001", "Main Door", "LOCKED", "10:15 AM");

    cout << "===== SMART HOME DASHBOARD =====" << endl;

    light.switchOn();
    thermostat.switchOn();
    camera.switchOn();
    doorLock.changeStatus("UNLOCKED");

    light.displayInfo();
    thermostat.displayInfo();
    camera.displayInfo();
    doorLock.displayInfo();

    return 0;
}