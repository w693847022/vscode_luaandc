#include<stdafx.h>

std::string Memo::getState() const
{
	return m_str;
}

void Memo::SetState(std::string &str)
{
	m_str = str;
}

void MemoContainer::Save(Memo memo)
{
	if(m_MemoContainer.size() < MAX_MEMO_SIZE)
	{
		m_MemoContainer.push_back(memo);
	}
	else
	{
		m_MemoContainer.pop_front();
		m_MemoContainer.push_back(memo);
	}
	m_CurrentPos = m_MemoContainer.size() - 1;
}

Memo MemoContainer::GoBack()
{
	if(m_CurrentPos >= 0)
	{
		return m_MemoContainer[m_CurrentPos--];
	}
	else{
		m_CurrentPos = m_MemoContainer.size()-1;
	}
	return Memo();
}

Memo LinuxShell::Execute()
{
	printf("Execute:%s\n",m_Str.c_str());
	Memo tempMemo;
	tempMemo.SetState(m_Str);
	m_Str.clear();
	return tempMemo;
}

void LinuxShell::Type(std::string str)
{
	printf("Type:%s\n",str.c_str());
	m_Str = str;
}

void LinuxShell::Load(Memo memo)
{
	m_Str = memo.getState();
}

void MemoClient::Run()
{
	MemoContainer memoCter;
	LinuxShell ls;

	ls.Type("do 1");
	memoCter.Save(ls.Execute());
	ls.Type("do 2");
	memoCter.Save(ls.Execute());
	ls.Type("do 3");
	memoCter.Save(ls.Execute());

	printf("back\n");

	ls.Load(memoCter.GoBack());
	ls.Execute();
	ls.Load(memoCter.GoBack());
	ls.Execute();
	ls.Load(memoCter.GoBack());
	ls.Execute();
}