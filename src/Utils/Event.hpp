#pragma once

#include <stdlib.h>

template <typename SourceType, typename... Arguments>
struct Callback
{
  Callback(void (*_method)(SourceType &source, Arguments &...args))
  {
    method = _method;
  }

  void call(SourceType &source, Arguments &...args) const
  {
    method(source, args...);
  }
  void call(SourceType *source, Arguments *...args) const
  {
    method(*source, *args...);
  }

  bool operator== (void (*_method)(SourceType &source, Arguments &...args))
  {
    return method == _method;
  }

  void (*method)(SourceType &source);
};

template <typename SourceType, typename... Arguments>
class Event
{
public:
  Event(SourceType *source) { _source = source; }
  Event(SourceType &source) { _source = &source; }

  void attachCallback(void (*callback)(SourceType &source, Arguments &...args))
  {
    _callbacks.emplace_back(callback);
  }

  void detachCallback(void (*callback)(SourceType &source, Arguments &...args))
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

  template <typename T>
  void redirect(Event<T> *ev)
  {
    _redirectionEvent = ev;
  }

  Event<SourceType, Arguments...> &operator+=(void (*callback)(SourceType &source, Arguments &...args))
  {
    attachCallback(callback);
    return *this;
  }
  Event<SourceType, Arguments...> &operator-=(void (*callback)(SourceType &source, Arguments &...args))
  {
    detachCallback(callback);
    return *this;
  }

  void trigger(Arguments &...args) const
  {
    if (_redirectionEvent)
    {
      _redirectionEvent->trigger(&args...);
    }
    else
    {
      if (_callbacks.empty())
        return;
      
      for (uint16_t i = 0; i < _callbacks.size(); i++)
      {
        _callbacks[i].call(_source, args...);
      }
    }
  }

protected:
  SourceType *_source;
  std::vector<Callback<SourceType, Arguments...>> _callbacks;
  Event *_redirectionEvent;
};