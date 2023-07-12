int totalGas = 0;  // Total gas available
    int currentGas = 0;  // Gas in the current tank
    int startStation = 0;  // Starting gas station index

    for (int i = 0; i < A.size(); i++) 
    {
        totalGas += A[i] - B[i];  // Calculate the total gas available

        if (currentGas < 0) {
            // If the current tank is empty, start from the next station
            startStation = i;
            currentGas = A[i] - B[i];
        } else {
            currentGas += A[i] - B[i];  // Fill the tank with gas
        }
    }

    if (totalGas < 0) 
    {
        // If the total gas available is negative, it's impossible to complete the circuit
        return -1;
    } 
    else 
    {
        return startStation;
    }
