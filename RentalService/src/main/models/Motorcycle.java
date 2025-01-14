package main.models;

public class Motorcycle extends Vehicle {
    private int engineCC;

    public Motorcycle(String licensePlate, String model, double dailyRate, int engineCC) {
        super(licensePlate, model, dailyRate);
        this.engineCC = engineCC;
    }

    @Override
    public double calculateRentalCost(int days) {
        double cost = days * getDailyRate();
        if (engineCC > 500) {
            cost += cost * 0.20; // Add 20% if engineCC > 500
        }
        return cost;
    }
}
