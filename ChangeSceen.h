#pragma once

class ChangeSceen
{
protected:
	enum Change 
	{
		GAMEPLAY,
		TITLE,
		GAMEOVER
	};

	Change scene_;
};
