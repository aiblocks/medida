//
// Copyright (c) 2012 Daniel Lundin
//

#ifndef MEDIDA_COUNTER_H_
#define MEDIDA_COUNTER_H_

#include <atomic>
#include <cstdint>

#include "medida/metric_interface.h"

namespace medida {

class Counter : public MetricInterface {
public:
  Counter(std::int64_t init = 0);
  ~Counter();
  void Process(MetricProcessor& processor);
  std::int64_t count() const;
  void set_count(std::int64_t n);
  void inc(std::int64_t n = 1);
  void dec(std::int64_t n = 1);
  void clear();
protected:
  std::atomic<std::int64_t> count_;
};

} // namespace medida

#endif // MEDIDA_COUNTER_H_
