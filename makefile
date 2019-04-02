final: UtPodDriver.o UtPod.o song.o
	g++ -o final UtPodDriver.o UtPod.o song.o
UtPodDriver.o: UtPodDriver.cpp UtPod.h Song.h
	g++ -c UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c UtPod.cpp
song.o: Song.cpp Song.h
	g++ -c Song.cpp
