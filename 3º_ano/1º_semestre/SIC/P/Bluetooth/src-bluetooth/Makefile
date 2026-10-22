CFLAGS = $(shell pkg-config --cflags glib-2.0) -g
LIBS = $(shell pkg-config --libs gio-2.0)

all: scan scan-plus scan-services name just_works

scan: scan.o dbus.o exit.o subscribe.o filter.o discovery.o
	$(CC) -g -o $@ $^ $(LIBS)

scan-plus: scan-plus.o dbus.o exit.o subscribe.o filter.o discovery.o
	$(CC) -g -o $@ $^ $(LIBS)

scan-services: scan-services.o dbus.o exit.o subscribe.o filter.o discovery.o connect.o gatt.o
	$(CC) -g -o $@ $^ $(LIBS)

name: name.o dbus.o exit.o
	$(CC) -g -o $@ $^ $(LIBS)

just_works: just_works.o dbus.o exit.o set_adapter_property.o just_works_agent.o
	$(CC) -g -o $@ $^ $(LIBS)

clean:
	-rm *.o scan scan-plus scan-services name just_works
