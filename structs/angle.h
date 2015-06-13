#include "vector.h"
class QAngle : public Vector
{
public:
	/*
	Calculates the angles needed to be set to aim at dst from src.
	(in) source pos
	(in) aim post
	(out) angles to set to
	Written by Snorflake
	ref: http://www.unknowncheats.me/forum/counterstrike-global-offensive/137492-math-behind-hack-1-coding-better-aimbot-stop-using-calcangle.html
	*/
	QAngle CalcAngle(Vector &src, Vector &dst)
	{
		QAngle angle;
		Vector delta = src - dst;
		double hypo = sqrt(delta.x * delta.x + delta.y * delta.y);
		angle.x = (atan(delta.z / hypo) * (180 / M_PI));
		angle.y = (atan(delta.y / delta.x) * (180 / M_PI));
		angle.z = 0.f;
		if (delta.x >= 0.f) angle.y += 180.f;
		return angle;
	}
};

typedef QAngle Angle;

/*
TODO:	
	Eventually make an Angle class with Angle-specific functions such as normalizing.
*/