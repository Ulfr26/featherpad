#include "EditorWindow.h"
#include "config.h"
#include <gtkmm.h>

int main(int argc, char* argv[]) {
    // I really don't know what that last argument does so I just put an unfunny meme.
    auto app = Gtk::Application::create(argc, argv, "my.name.jeff");

    EditorWindow window;

    return app->run(window);
}
