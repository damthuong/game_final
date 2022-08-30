#include "GameStateBase.h"
#include "GSIntro.h"
#include "GSPlay.h"
#include "GSEnd.h"


GameStateBase* GameStateBase::CreateState(StateTypes st) {
	GameStateBase* gs = nullptr;
	switch (st)
	{
	case INVALID:
		break;
	case INTRO:
		gs = new GSIntro();
		break;
	case PLAY:
		gs = new GSPlay();
		break;
	case END:
		gs = new GSEnd();
		break;
	default:
		break;
	}
	return gs;
}