#pragma once

#ifndef C_H
#define C_H

template<class T>
class Container {
	public:
		T object_0;
	public:
		Container() { this->object_0 = T(); }
		Container(const T& object_0) { this->object_0 = object_0; }
		virtual ~Container() {}
};

template<class T0, class T1>
class ContainerDouble : public Container<T0> {
	public:
		T1 object_1;
	public:
		ContainerDouble() : Container<T0>() { this->object_1 = T1(); }
		ContainerDouble(const T0& object_0, const T1& object_1) : Container<T0>(object_0) { this->object_1 = object_1; }
		virtual ~ContainerDouble() {}
};

template<class T0, class T1, class T2>
class ContainerTriple : public ContainerDouble<T0, T1> {
	public:
		T2 object_2;
	public:
		ContainerTriple() : ContainerDouble<T0, T1>() { this->object_2 = T2(); }
		ContainerTriple(const T0& object_0, const T1& object_1, const T2& object_2) : ContainerDouble<T0, T1>(object_0, object_1) { this->object_2 = object_2; }
		virtual ~ContainerTriple() {}
};

#endif /* C_H */
