class AbstractState;
class ForumAccount
{
	public:
	FourmAccount(string name);

	inline AbstractState* GetState()
	{
		return this->state;
	}
	inline void SetState(AbstractState* state);
	{
		this->state = state;
	}
	inline string GetName()
	{
		return this->name;
	}

	void DownloadFile(int score);
	void WriteNote(int score);
	void ReplyNote(int score);
	private:
	AbstractState *state;
	string name;
}

class AbstractState
{
	public:
	virtual void CheckState(int score) = 0;
	virtual void DownloadFile(int score){}
	virtual void WriteNote(int score){}
	virtual void ReplyNote(int score){}

	inline void SetPoint(int p){
		this->point = p;
	}
	inline int GetPoint()
	{
		return this->point;
	}
	inline void SetName(string name)
	{
		this->name = name;
	}
	private:
	ForumAccount *acc;
	string stateName;
	int point;
}

