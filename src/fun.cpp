unsigned int faStr1(const char *str)
{
	int kol = 0;
	bool word = false;
	bool number = false;
	int i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (!word && str[i] != ' ')
		{
			word = true;
			if (str[i] <= 57 && str[i] >= 48)
				number = true;
		}
		else if (word && str[i] != ' ')
		{
			if (str[i] <= 57 && str[i] >= 48)
				number = true;
		}
		else
		{
			if (!number && word)
				kol++;
			word = false;
			number = false;
		}
		i++;
	}
	if (!number && word)
		kol++;

	return kol;
}

unsigned int faStr2(const char *str)
{
	bool small = true;
	bool big = false;
	bool word = false;
	int kol = 0;
	int i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (!word && str[i] != ' ')
		{
			word = true;
			if (str[i] >= 65 && str[i] <= 90)
				big = true;
		}
		else if (word && str[i] != ' ')
		{
			if (str[i] < 97 || str[i] > 122)
				small = false;
		}
		else
		{
			if (big && small && word)
				kol++;
			word = false;
			small = true;
			big = false;
		}
		i++;
	}
	if (big && small && word)
		kol++;

	return kol;
}

unsigned int faStr3(const char *str)
{
	double sum = 0.0;
	int i = 0;
	int kol = 0;
	int length = 0;
	bool word = false;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (!word && str[i] != ' ')
		{
			word = true;
			length++;
			kol++;
		}
		else if (word && str[i] != ' ')
		{
			length++;
		}
		else
		{
			word = false;
			sum += length;
			length = 0;
		}
		i++;
	}
	if (word)
		sum += length;
	sum /= kol;
	int result = sum;
	if (sum - result >= 0.5)
		result++;

	return result;
}
