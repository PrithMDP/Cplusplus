#include <iostream>
using std::cout;
using std::endl;

const unsigned N = 40000;

/******************************************************************************
 * A Regular class
 * ****************************************************************************/
class Regular {
public:
    void tick(uint64_t n) {
        this->counter += n;
    }

    uint64_t getvalue() {
        return this->counter;
    }

private:
    uint64_t counter = 0;
};
void run_reg(Regular* obj) {
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      obj->tick(j);
    }
  }
}
/******************************************************************************
 * A regular class
 * ****************************************************************************/


/******************************************************************************
 * A polymorphic base class
 * ****************************************************************************/
class DynamicInterface {
public:
  virtual void tick(uint64_t n) = 0;
  virtual uint64_t getvalue() = 0;
};

class DynamicImplementation : public DynamicInterface {
  uint64_t counter;

public:
  DynamicImplementation()
    : counter(0) {
  }

  virtual void tick(uint64_t n) {
    counter += n;
  }

  virtual uint64_t getvalue() {
    return counter;
  }
};


void run_dynamic(DynamicInterface* obj) {
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      obj->tick(j);
    }
  }
}
/******************************************************************************
 * A polymorphic base class
 * ****************************************************************************/


/******************************************************************************
 * A templated interface
 * ****************************************************************************/
template <typename Implementation>
class CRTPInterface {
public:
  void tick(uint64_t n) {
    impl().tick(n);
  }

  uint64_t getvalue() {
    return impl().getvalue();
  }
private:
  Implementation& impl() {
    return *static_cast<Implementation*>(this);
  }
};

class CRTPImplementation : public CRTPInterface<CRTPImplementation> {
  uint64_t counter;
public:
  CRTPImplementation()
    : counter(0) {
  }

  void tick(uint64_t n) {
    counter += n;
  }

  uint64_t getvalue() {
    return counter;
  }
};

template <typename Implementation>
void run_crtp(CRTPInterface<Implementation>* obj) {
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      obj->tick(j);
    }
  }
}
/******************************************************************************
 * A templated interface
 * ****************************************************************************/

int main() {
    
#if defined(TEMPLATE)
    CRTPInterface<CRTPImplementation>* obj = new CRTPInterface<CRTPImplementation>;
    run_crtp(obj);
#elif defined(DYNAMIC)
    DynamicInterface* obj = new DynamicImplementation();
    run_dynamic(obj);
#else
    Regular* obj = new Regular;
    run_reg(obj);
#endif
    cout << obj->getvalue() << endl;

    return 0;
}
