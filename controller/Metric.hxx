// systemtap health monitor
// Copyright (C) 2010 Aaron Luchko
//
// This file is part of systemtap, and is free software.  You can
// redistribute it and/or modify it under the terms of the GNU General
// Public License (GPL); either version 2, or (at your option) any
// later version.
#ifndef METRIC_H
#define METRIC_H 1

#include "Message.hxx"
#include "MetricType.hxx"

// A Metric contains all the information for a single metric reported by a monitor.
namespace systemtap
{
class Metric
{
private:
  int id;
  char* name;
  MetricType* type;
  int n;
  double m2; // term for variance algorithm
  double mean;
  double currentVal;
  double time;
  bool updated;
public:
  Metric(MetricType* metricType, char* metricName);
  ~Metric();
  void setId(int id);
  int getId();
  char* getName();
  // update the Metric with the given message
  void update(double time, double value);
  // the average value of the metric
  double getMean();
  // the standard deviation
  double getStd();
  // generally only used when saving/loading from DB
  void setMean(double mean);
  void setM2(double m2);
  void setNumSamples(int numSamples);
  void setCurrentValue(double currentValue);
  void setTime(double time);
  double getM2();
  double getTime();
  int getNumSamples();
  double getCurrentValue();
  bool isUpdated();
  bool setUpdated(bool updated);
  MetricType* getType(){return type;}

};
}
#endif
