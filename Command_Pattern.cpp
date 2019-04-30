#include <bits/stdc++.h>

using namespace std;

/*
命令模式(Command Pattern)：将一个请求封装为一个对象，从而使我们可用不同的请求对客户进行参数化；对请求排队或者记录请求日志，以及支持可撤销的操作。
命令模式是一种对象行为型模式，其别名为动作(Action)模式或事务(Transaction)模式。
*/

/* 声明命令接口 */
class Command { 
public:
    ~Command() = default;
    Command() = default;
    virtual void execute() {};
    virtual void undo() {};
};

class Light {
public:
    Light(string name) : name(name) {}
    Light(const Light & rhs) {
        name = rhs.name;
    }
    ~Light() {}
    void on() {
        cout << "turn on " << this->name << endl; 
    }
    void off() {
        cout << "trun off " << this->name << endl;
    }
private:
    string name;
};

// 开灯命令
class LightOnCommand : public Command {
public:
    LightOnCommand():light("灯random") {}
    LightOnCommand(const Light & rhs) : light(rhs) {}
    ~LightOnCommand() {}
    // 重写
    virtual void execute() override {
        light.on();
    }
    virtual void undo() override {
        light.off();
    }
private:
    Light light; 
};

class SimpleRemoteControl {
public:
    SimpleRemoteControl() {}
    void setCommond(Command* command) {
        this->slot = command;
    }
    void buttonWasPressed() {
        slot->execute();
    }
private:
    Command *slot;
};

int main()
{
    Command* command = new LightOnCommand();
    SimpleRemoteControl* ctr = new SimpleRemoteControl();
    ctr->setCommond(command);
    ctr->buttonWasPressed();
    delete command;
    delete ctr;
    return 0;
}

