#include<stdafx.h>


void AbstractManager::SetNextManager(AbstractManager *manager)
{
	m_supervisorManager = manager;
}

void JuniorManager::HandleRequest(const double &fee)
{
	printf("JuniroManager Handle: ");
	if(fee < m_approvalLimit)
	{
		printf("success approval fee!\n");
	}
	else if(m_supervisorManager == 0)
	{
		printf("i can't approval.\n");
	}
	else
	{
		printf("hand to my supervisor.\n");
		m_supervisorManager->HandleRequest(fee);
	}
}

void SeniorManager::HandleRequest(const double &fee)
{
	printf("SeniorManager Handle: ");
	if(fee < m_approvalLimit)
	{
		printf("success approval fee!\n");
	}
	else if(m_supervisorManager == 0)
	{
		printf("i can't approval.\n");
	}
	else
	{
		printf("hand to my supervisor.\n");
		m_supervisorManager->HandleRequest(fee);
	}
}

void ChainOfPesponsibilityClient::Run()
{
	AbstractManager *juniorManager = new JuniorManager(5000);
	AbstractManager *seniorManager = new SeniorManager(50000);

	juniorManager->SetNextManager(seniorManager);

	int fee = 500;
	for(int i= 0;i<3;i++)
	{
		printf("approval %d\n",fee);
		juniorManager->HandleRequest(fee);
		fee *= 10;
	}
}