#ifndef DRAW_H
#define DRAW_H

class Draw {
    static Draw *_instance;
public:
    static Draw *get_instance();
    void init();
    void run_start();
    void run();
    void run_end();
    void end();

public:
    ~Draw();
    
    void change_frame(int width, int height);
    void set_glad_gl_loader();
};

#endif
