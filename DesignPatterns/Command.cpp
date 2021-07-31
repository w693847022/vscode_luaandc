#include<stdafx.h>
void TV::TurnOn()
{
	printf("tv turn on\n");
}
void TV::TurnOff()
{
	printf("tv turn off\n");
}
void TV::NextChannel()
{
	++m_channel;
	printf("next to channel:%d\n",m_channel);
}
void TV::LastChannel()
{
	--m_channel;
	printf("last to channel:%d\n",m_channel);
}
void TurnOnCommand::execute()
{
	m_tv->TurnOn();
}
void TurnOffCommand::execute()
{
	m_tv->TurnOff();
}
void NextChannelCommand::execute()
{
	m_tv->NextChannel();
}
void LastChannelCommand::execute()
{
	m_tv->LastChannel();
}
void RemoteControl::operate(Command *command)
{
	command->execute();
}
void CommandModelClient::Run()
{
	TV *tv = new TV();
	Command *turnOn = new TurnOnCommand(tv);
	Command *turnOff = new TurnOffCommand(tv);
	Command *nextChannel = new NextChannelCommand(tv);
	Command *lastChannel = new LastChannelCommand(tv);

	RemoteControl::operate(turnOn);
	RemoteControl::operate(turnOff);
	RemoteControl::operate(nextChannel);
	RemoteControl::operate(lastChannel);
}