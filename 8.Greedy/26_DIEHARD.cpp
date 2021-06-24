int solve(int h, int a)
{
	h += 3;
	a += 2;
	int count = 1;
	while(true)
	{
		if(h > 5 && a > 10)
		{
			h -= 2;		a -= 8;
			count += 2;
		}
		else if(h > 20 && a <= 10)
		{
			h -= 17;	a += 7;
			count += 2;
		}
		else
		{
			return count;
		}
	}
}