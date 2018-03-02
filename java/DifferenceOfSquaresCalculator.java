class DifferenceOfSquaresCalculator{

    int computeDifferenceOfSquares(int num) {
        return computeSquareOfSumTo(num) - computeSumOfSquaresTo(num);
    }

    int computeSquareOfSumTo(int num) {
       int sum = 0;
       for(int i = 1; i <= num; i++) 
          sum += i;    
       return sum*sum;
    }

    int computeSumOfSquaresTo(int num) {
        int sum = 0;
        for(int i = 1; i <= num; i++)
           sum += i*i;      
        return sum;
    }
}

