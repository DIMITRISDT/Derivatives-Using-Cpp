#ifndef DERIVATIVES_H 
#define DERIVATIVES_H

class Random {
    int x;
public:
    Random(int c);
    virtual ~Random();
    int get() const;
    void set(int c);
};

#endif
