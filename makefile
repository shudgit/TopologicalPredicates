all:
	g++ -Wzero-as-null-pointer-constant -c -I ../TopologicalPredicates \
		AttributedHalfSegment2D.cpp \
		EventPoint.cpp \
		HalfSegment2D.cpp \
		Line2D.cpp \
		Number.cpp \
		ParallelObjTraversal.cpp \
		PlaneSweep.cpp \
		VerifyPredicate.cpp \
		main.cpp \
		Point2D.cpp \
		Region2D.cpp \
		Segment2D.cpp \
		SimplePoint2D.cpp
	g++ AttributedHalfSegment2D.o \
		EventPoint.o \
		HalfSegment2D.o \
		Line2D.o \
		Number.o \
		ParallelObjTraversal.o \
		PlaneSweep.o \
		VerifyPredicate.o \
		main.o \
		Point2D.o \
		Region2D.o \
		Segment2D.o \
		SimplePoint2D.o
	ar crf ../TopologicalPredicates/libTopologicalPredicates.a *.o
	g++ main.cpp -lTopologicalPredicates.a -lgmp -lgmpxx -o test

clean:
	rm *.o