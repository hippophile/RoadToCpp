package main.models;

import main.interfaces.Rentable;

public abstract class Vehicle implements Rentable {
    private String licensePlate;
    private String model;
    private double dailyRate;

    public Vehicle(String licensePlate, String model, double dailyRate) {
        this.licensePlate = licensePlate;
        this.model = model;
        this.dailyRate = dailyRate;
    }

    public String getLicensePlate() {
        return licensePlate;
    }

    public String getModel() {
        return model;
    }

    public double getDailyRate() {
        return dailyRate;
    }

    @Override
    public String getDetails() {
        return "License Plate: " + licensePlate + ", Model: " + model + ", Daily Rate: " + dailyRate;
    }
}
