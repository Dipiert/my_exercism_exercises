component {	
	/**
	* @year The input year to consider
	*
	* @returns A boolean for whether the inputted year is true or false
	*/
	 function isLeapYear( year ) {
		return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)
	}	
}

