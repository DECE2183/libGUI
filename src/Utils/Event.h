#pragma once
#include <stdlib.h>

enum EventType
{
  Click,
  EventsCount,
};

template <typename SourceType>
struct Callback
{
  Callback(void (*_method)(SourceType &source))
  {
    method = _method;
  }

  void call(SourceType &source) const
  {
    method(source);
  }
  void call(SourceType *source) const
  {
    method(*source);
  }

  bool operator== (void (*_method)(SourceType &source))
  {
    return method == _method;
  }

  void (*method)(SourceType &source);
};

template <typename SourceType>
class Event
{
public:
  Event(SourceType *source) { _source = source; }
  Event(SourceType &source) { _source = &source; }

  void attachCallback(void (*callback)(SourceType &source))
  {
    _callbacks.emplace_back(callback);
  }

  void detachCallback(void (*callback)(SourceType &source))
  {
    for (uint16_t i = 0; i < _callbacks.size(); i++)
    {
      if (_callbacks[i] == callback)
      {
        _callbacks.erase(_callbacks.begin() + i);
        return;
      }
    }
  }

  Event<SourceType> &operator+=(void (*callback)(SourceType &source))
  {
    attachCallback(callback);
    return *this;
  }
  Event<SourceType> &operator-=(void (*callback)(SourceType &source))
  {
    detachCallback(callback);
    return *this;
  }

  void trigger() const
  {
    if (_callbacks.empty())
      return;
    
    for (uint16_t i = 0; i < _callbacks.size(); i++)
    {
      _callbacks[i].call(_source);
    }
  }

protected:
  SourceType *_source;
  std::vector<Callback<SourceType>> _callbacks;
};