typedef struct {
	int lEncVal,
		lEncLast,
		rEncVal,
		rEncLast,
		time,
		timeLast;
	tSensors lEnc,
		rEnc;
	float x,
		y,
		theta,
		convertToDegs;
} Pos;

void updatePos(Pos *pos) {
	pos->lEncLast = pos->lEncVal;
	pos->rEncLast = pos->rEncVal;
	pos->timeLast = pos->time;
	pos->lEncVal = SensorValue[pos->lEnc];
	pos->rEncVal = SensorValue[pos->rEnc];
	pos->time = nSysTime;

	pos->theta = (pos->lEncVal - pos->rEncVal) * pos->convertToDegs % 360;

	pos->x = pos->x - (sin(pos->theta) * (.5 * ((pos->lEncVal - pos->lEncLast) + (pos->rEncVal - pos->rEncLast))));
	pos->y = pos->y + (cos(pos->theta) * (.5 * ((pos->lEncVal - pos->lEncLast) + (pos->rEncVal - pos->rEncLast))));
}
