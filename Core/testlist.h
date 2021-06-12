
include / bits
stl_list.h
Go to the documentation of this file.

00001 // List implementation -*- C++ -*-
00002
00003 // Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
00004 //
00005 // This file is part of the GNU ISO C++ Library.  This library is free
00006 // software; you can redistribute it and/or modify it under the
00007 // terms of the GNU General Public License as published by the
00008 // Free Software Foundation; either version 2, or (at your option)
00009 // any later version.
00010
00011 // This library is distributed in the hope that it will be useful,
00012 // but WITHOUT ANY WARRANTY; without even the implied warranty of
00013 // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
00014 // GNU General Public License for more details.
00015
00016 // You should have received a copy of the GNU General Public License along
00017 // with this library; see the file COPYING.  If not, write to the Free
00018 // Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
00019 // USA.
00020
00021 // As a special exception, you may use this file as part of a free software
00022 // library without restriction.  Specifically, if other files instantiate
00023 // templates or use macros or inline functions from this file, or you compile
00024 // this file and link it with other files to produce an executable, this
00025 // file does not by itself cause the resulting executable to be covered by
00026 // the GNU General Public License.  This exception does not however
00027 // invalidate any other reasons why the executable file might be covered by
00028 // the GNU General Public License.
00029
00030 /*
00031  *
00032  * Copyright (c) 1994
00033  * Hewlett-Packard Company
00034  *
00035  * Permission to use, copy, modify, distribute and sell this software
00036  * and its documentation for any purpose is hereby granted without fee,
00037  * provided that the above copyright notice appear in all copies and
00038  * that both that copyright notice and this permission notice appear
00039  * in supporting documentation.  Hewlett-Packard Company makes no
00040  * representations about the suitability of this software for any
00041  * purpose.  It is provided "as is" without express or implied warranty.
00042  *
00043  *
00044  * Copyright (c) 1996,1997
00045  * Silicon Graphics Computer Systems, Inc.
00046  *
00047  * Permission to use, copy, modify, distribute and sell this software
00048  * and its documentation for any purpose is hereby granted without fee,
00049  * provided that the above copyright notice appear in all copies and
00050  * that both that copyright notice and this permission notice appear
00051  * in supporting documentation.  Silicon Graphics makes no
00052  * representations about the suitability of this software for any
00053  * purpose.  It is provided "as is" without express or implied warranty.
00054  */
00055
00056 /** @file stl_list.h
00057  *  This is an internal header file, included by other library headers.
00058  *  You should not attempt to use it directly.
00059  */
00060
00061 #ifndef _LIST_H
00062 #define _LIST_H 1
00063
00064 #include <bits/concept_check.h>
00065
00066 namespace _GLIBCXX_STD
00067 {
00068   // Supporting structures are split into common and templated types; the
00069   // latter publicly inherits from the former in an effort to reduce code
00070   // duplication.  This results in some "needless" static_cast'ing later on,
00071   // but it's all safe downcasting.
00072
00073   /// @if maint Common part of a node in the %list.  @endif
00074   struct _List_node_base
00075   {
00076     _List_node_base* _M_next;   ///< Self-explanatory
00077     _List_node_base* _M_prev;   ///< Self-explanatory
00078
00079     static void
00080     swap(_List_node_base& __x, _List_node_base& __y);
00081
00082     void
00083     transfer(_List_node_base * const __first,
00084          _List_node_base * const __last);
00085
00086     void
00087     reverse();
00088
00089     void
00090     hook(_List_node_base * const __position);
00091
00092     void
00093     unhook();
00094   };
00095
00096   /// @if maint An actual node in the %list.  @endif
00097   template<typename _Tp>
00098     struct _List_node : public _List_node_base
00099     {
00100       _Tp _M_data;                ///< User's data.
00101     };
00102
00103   /**
00104    *  @brief A list::iterator.
00105    *
00106    *  @if maint
00107    *  All the functions are op overloads.
00108    *  @endif
00109   */
00110   template<typename _Tp>
00111     struct _List_iterator
00112     {
00113       typedef _List_iterator<_Tp>           _Self;
00114       typedef _List_node<_Tp>               _Node;
00115
00116       typedef ptrdiff_t                     difference_type;
00117       typedef bidirectional_iterator_tag    iterator_category;
00118       typedef _Tp                           value_type;
00119       typedef _Tp*                          pointer;
00120       typedef _Tp&                          reference;
00121
00122       _List_iterator()
00123       : _M_node() { }
00124
00125       _List_iterator(_List_node_base* __x)
00126       : _M_node(__x) { }
00127
00128       // Must downcast from List_node_base to _List_node to get to _M_data.
00129       reference
00130       operator*() const
00131       { return static_cast<_Node*>(_M_node)->_M_data; }
00132
00133       pointer
00134       operator->() const
00135       { return &static_cast<_Node*>(_M_node)->_M_data; }
00136
00137       _Self&
00138       operator++()
00139       {
00140     _M_node = _M_node->_M_next;
00141     return *this;
00142       }
00143
00144       _Self
00145       operator++(int)
00146       {
00147     _Self __tmp = *this;
00148     _M_node = _M_node->_M_next;
00149     return __tmp;
00150       }
00151
00152       _Self&
00153       operator--()
00154       {
00155     _M_node = _M_node->_M_prev;
00156     return *this;
00157       }
00158
00159       _Self
00160       operator--(int)
00161       {
00162     _Self __tmp = *this;
00163     _M_node = _M_node->_M_prev;
00164     return __tmp;
00165       }
00166
00167       bool
00168       operator==(const _Self& __x) const
00169       { return _M_node == __x._M_node; }
00170
00171       bool
00172       operator!=(const _Self& __x) const
00173       { return _M_node != __x._M_node; }
00174
00175       // The only member points to the %list element.
00176       _List_node_base* _M_node;
00177     };
00178
00179   /**
00180    *  @brief A list::const_iterator.
00181    *
00182    *  @if maint
00183    *  All the functions are op overloads.
00184    *  @endif
00185   */
00186   template<typename _Tp>
00187     struct _List_const_iterator
00188     {
00189       typedef _List_const_iterator<_Tp>     _Self;
00190       typedef const _List_node<_Tp>         _Node;
00191       typedef _List_iterator<_Tp>           iterator;
00192
00193       typedef ptrdiff_t                     difference_type;
00194       typedef bidirectional_iterator_tag    iterator_category;
00195       typedef _Tp                           value_type;
00196       typedef const _Tp*                    pointer;
00197       typedef const _Tp&                    reference;
00198
00199       _List_const_iterator()
00200       : _M_node() { }
00201
00202       _List_const_iterator(const _List_node_base* __x)
00203       : _M_node(__x) { }
00204
00205       _List_const_iterator(const iterator& __x)
00206       : _M_node(__x._M_node) { }
00207
00208       // Must downcast from List_node_base to _List_node to get to
00209       // _M_data.
00210       reference
00211       operator*() const
00212       { return static_cast<_Node*>(_M_node)->_M_data; }
00213
00214       pointer
00215       operator->() const
00216       { return &static_cast<_Node*>(_M_node)->_M_data; }
00217
00218       _Self&
00219       operator++()
00220       {
00221     _M_node = _M_node->_M_next;
00222     return *this;
00223       }
00224
00225       _Self
00226       operator++(int)
00227       {
00228     _Self __tmp = *this;
00229     _M_node = _M_node->_M_next;
00230     return __tmp;
00231       }
00232
00233       _Self&
00234       operator--()
00235       {
00236     _M_node = _M_node->_M_prev;
00237     return *this;
00238       }
00239
00240       _Self
00241       operator--(int)
00242       {
00243     _Self __tmp = *this;
00244     _M_node = _M_node->_M_prev;
00245     return __tmp;
00246       }
00247
00248       bool
00249       operator==(const _Self& __x) const
00250       { return _M_node == __x._M_node; }
00251
00252       bool
00253       operator!=(const _Self& __x) const
00254       { return _M_node != __x._M_node; }
00255
00256       // The only member points to the %list element.
00257       const _List_node_base* _M_node;
00258     };
00259
00260   template<typename _Val>
00261     inline bool
00262     operator==(const _List_iterator<_Val>& __x,
00263            const _List_const_iterator<_Val>& __y)
00264     { return __x._M_node == __y._M_node; }
00265
00266   template<typename _Val>
00267     inline bool
00268     operator!=(const _List_iterator<_Val>& __x,
00269                const _List_const_iterator<_Val>& __y)
00270     { return __x._M_node != __y._M_node; }
00271
00272
00273   /**
00274    *  @if maint
00275    *  See bits/stl_deque.h's _Deque_base for an explanation.
00276    *  @endif
00277   */
00278   template<typename _Tp, typename _Alloc>
00279     class _List_base
00280     {
00281     protected:
00282       // NOTA BENE
00283       // The stored instance is not actually of "allocator_type"'s
00284       // type.  Instead we rebind the type to
00285       // Allocator<List_node<Tp>>, which according to [20.1.5]/4
00286       // should probably be the same.  List_node<Tp> is not the same
00287       // size as Tp (it's two pointers larger), and specializations on
00288       // Tp may go unused because List_node<Tp> is being bound
00289       // instead.
00290       //
00291       // We put this to the test in the constructors and in
00292       // get_allocator, where we use conversions between
00293       // allocator_type and _Node_Alloc_type. The conversion is
00294       // required by table 32 in [20.1.5].
00295       typedef typename _Alloc::template rebind<_List_node<_Tp> >::other
00296
00297       _Node_Alloc_type;
00298
00299       struct _List_impl
00300     : public _Node_Alloc_type {
00301     _List_node_base _M_node;
00302     _List_impl (const _Node_Alloc_type& __a)
00303       : _Node_Alloc_type(__a)
00304     { }
00305       };
00306
00307       _List_impl _M_impl;
00308
00309       _List_node<_Tp>*
00310       _M_get_node()
00311       { return _M_impl._Node_Alloc_type::allocate(1); }
00312
00313       void
00314       _M_put_node(_List_node<_Tp>* __p)
00315       { _M_impl._Node_Alloc_type::deallocate(__p, 1); }
00316
00317   public:
00318       typedef _Alloc allocator_type;
00319
00320       allocator_type
00321       get_allocator() const
00322       { return allocator_type(*static_cast<const _Node_Alloc_type*>(&this->_M_impl)); }
00323
00324       _List_base(const allocator_type& __a)
00325     : _M_impl(__a)
00326       { _M_init(); }
00327
00328       // This is what actually destroys the list.
00329       ~_List_base()
00330       { _M_clear(); }
00331
00332       void
00333       _M_clear();
00334
00335       void
00336       _M_init()
00337       {
00338         this->_M_impl._M_node._M_next = &this->_M_impl._M_node;
00339         this->_M_impl._M_node._M_prev = &this->_M_impl._M_node;
00340       }
00341     };
00342
00343   /**
00344    *  @brief A standard container with linear time access to elements,
00345    *  and fixed time insertion/deletion at any point in the sequence.
00346    *
00347    *  @ingroup Containers
00348    *  @ingroup Sequences
00349    *
00350    *  Meets the requirements of a <a href="tables.html#65">container</a>, a
00351    *  <a href="tables.html#66">reversible container</a>, and a
00352    *  <a href="tables.html#67">sequence</a>, including the
00353    *  <a href="tables.html#68">optional sequence requirements</a> with the
00354    *  %exception of @c at and @c operator[].
00355    *
00356    *  This is a @e doubly @e linked %list.  Traversal up and down the
00357    *  %list requires linear time, but adding and removing elements (or
00358    *  @e nodes) is done in constant time, regardless of where the
00359    *  change takes place.  Unlike std::vector and std::deque,
00360    *  random-access iterators are not provided, so subscripting ( @c
00361    *  [] ) access is not allowed.  For algorithms which only need
00362    *  sequential access, this lack makes no difference.
00363    *
00364    *  Also unlike the other standard containers, std::list provides
00365    *  specialized algorithms %unique to linked lists, such as
00366    *  splicing, sorting, and in-place reversal.
00367    *
00368    *  @if maint
00369    *  A couple points on memory allocation for list<Tp>:
00370    *
00371    *  First, we never actually allocate a Tp, we allocate
00372    *  List_node<Tp>'s and trust [20.1.5]/4 to DTRT.  This is to ensure
00373    *  that after elements from %list<X,Alloc1> are spliced into
00374    *  %list<X,Alloc2>, destroying the memory of the second %list is a
00375    *  valid operation, i.e., Alloc1 giveth and Alloc2 taketh away.
00376    *
00377    *  Second, a %list conceptually represented as
00378    *  @code
00379    *    A <---> B <---> C <---> D
00380    *  @endcode
00381    *  is actually circular; a link exists between A and D.  The %list
00382    *  class holds (as its only data member) a private list::iterator
00383    *  pointing to @e D, not to @e A!  To get to the head of the %list,
00384    *  we start at the tail and move forward by one.  When this member
00385    *  iterator's next/previous pointers refer to itself, the %list is
00386    *  %empty.  @endif
00387   */
00388   template<typename _Tp, typename _Alloc = allocator<_Tp> >
00389     class list : protected _List_base<_Tp, _Alloc>
00390     {
00391       // concept requirements
00392       __glibcxx_class_requires(_Tp, _SGIAssignableConcept)
00393
00394       typedef _List_base<_Tp, _Alloc>                   _Base;
00395
00396     public:
00397       typedef _Tp                                        value_type;
00398       typedef typename _Alloc::pointer                   pointer;
00399       typedef typename _Alloc::const_pointer             const_pointer;
00400       typedef typename _Alloc::reference                 reference;
00401       typedef typename _Alloc::const_reference           const_reference;
00402       typedef _List_iterator<_Tp>                        iterator;
00403       typedef _List_const_iterator<_Tp>                  const_iterator;
00404       typedef std::reverse_iterator<const_iterator>      const_reverse_iterator;
00405       typedef std::reverse_iterator<iterator>            reverse_iterator;
00406       typedef size_t                                     size_type;
00407       typedef ptrdiff_t                                  difference_type;
00408       typedef typename _Base::allocator_type             allocator_type;
00409
00410     protected:
00411       // Note that pointers-to-_Node's can be ctor-converted to
00412       // iterator types.
00413       typedef _List_node<_Tp>               _Node;
00414
00415       /** @if maint
00416        *  One data member plus two memory-handling functions.  If the
00417        *  _Alloc type requires separate instances, then one of those
00418        *  will also be included, accumulated from the topmost parent.
00419        *  @endif
00420        */
00421       using _Base::_M_impl;
00422       using _Base::_M_put_node;
00423       using _Base::_M_get_node;
00424
00425       /**
00426        *  @if maint
00427        *  @param  x  An instance of user data.
00428        *
00429        *  Allocates space for a new node and constructs a copy of @a x in it.
00430        *  @endif
00431        */
00432       _Node*
00433       _M_create_node(const value_type& __x)
00434       {
00435     _Node* __p = this->_M_get_node();
00436     try
00437       {
00438         std::_Construct(&__p->_M_data, __x);
00439       }
00440     catch(...)
00441       {
00442         _M_put_node(__p);
00443         __throw_exception_again;
00444       }
00445     return __p;
00446       }
00447
00448       /**
00449        *  @if maint
00450        *  Allocates space for a new node and default-constructs a new
00451        *  instance of @c value_type in it.
00452        *  @endif
00453        */
00454       _Node*
00455       _M_create_node()
00456       {
00457     _Node* __p = this->_M_get_node();
00458     try
00459       {
00460         std::_Construct(&__p->_M_data);
00461       }
00462     catch(...)
00463       {
00464         _M_put_node(__p);
00465         __throw_exception_again;
00466       }
00467     return __p;
00468       }
00469
00470     public:
00471       // [23.2.2.1] construct/copy/destroy
00472       // (assign() and get_allocator() are also listed in this section)
00473       /**
00474        *  @brief  Default constructor creates no elements.
00475        */
00476       explicit
00477       list(const allocator_type& __a = allocator_type())
00478       : _Base(__a) { }
00479
00480       /**
00481        *  @brief  Create a %list with copies of an exemplar element.
00482        *  @param  n  The number of elements to initially create.
00483        *  @param  value  An element to copy.
00484        *
00485        *  This constructor fills the %list with @a n copies of @a value.
00486        */
00487       list(size_type __n, const value_type& __value,
00488        const allocator_type& __a = allocator_type())
00489       : _Base(__a)
00490       { this->insert(begin(), __n, __value); }
00491
00492       /**
00493        *  @brief  Create a %list with default elements.
00494        *  @param  n  The number of elements to initially create.
00495        *
00496        *  This constructor fills the %list with @a n copies of a
00497        *  default-constructed element.
00498        */
00499       explicit
00500       list(size_type __n)
00501       : _Base(allocator_type())
00502       { this->insert(begin(), __n, value_type()); }
00503
00504       /**
00505        *  @brief  %List copy constructor.
00506        *  @param  x  A %list of identical element and allocator types.
00507        *
00508        *  The newly-created %list uses a copy of the allocation object used
00509        *  by @a x.
00510        */
00511       list(const list& __x)
00512       : _Base(__x.get_allocator())
00513       { this->insert(begin(), __x.begin(), __x.end()); }
00514
00515       /**
00516        *  @brief  Builds a %list from a range.
00517        *  @param  first  An input iterator.
00518        *  @param  last  An input iterator.
00519        *
00520        *  Create a %list consisting of copies of the elements from
00521        *  [@a first,@a last).  This is linear in N (where N is
00522        *  distance(@a first,@a last)).
00523        *
00524        *  @if maint
00525        *  We don't need any dispatching tricks here, because insert does all of
00526        *  that anyway.
00527        *  @endif
00528        */
00529       template<typename _InputIterator>
00530         list(_InputIterator __first, _InputIterator __last,
00531          const allocator_type& __a = allocator_type())
00532         : _Base(__a)
00533         { this->insert(begin(), __first, __last); }
00534
00535       /**
00536        *  No explicit dtor needed as the _Base dtor takes care of
00537        *  things.  The _Base dtor only erases the elements, and note
00538        *  that if the elements themselves are pointers, the pointed-to
00539        *  memory is not touched in any way.  Managing the pointer is
00540        *  the user's responsibilty.
00541        */
00542
00543       /**
00544        *  @brief  %List assignment operator.
00545        *  @param  x  A %list of identical element and allocator types.
00546        *
00547        *  All the elements of @a x are copied, but unlike the copy
00548        *  constructor, the allocator object is not copied.
00549        */
00550       list&
00551       operator=(const list& __x);
00552
00553       /**
00554        *  @brief  Assigns a given value to a %list.
00555        *  @param  n  Number of elements to be assigned.
00556        *  @param  val  Value to be assigned.
00557        *
00558        *  This function fills a %list with @a n copies of the given
00559        *  value.  Note that the assignment completely changes the %list
00560        *  and that the resulting %list's size is the same as the number
00561        *  of elements assigned.  Old data may be lost.
00562        */
00563       void
00564       assign(size_type __n, const value_type& __val)
00565       { _M_fill_assign(__n, __val); }
00566
00567       /**
00568        *  @brief  Assigns a range to a %list.
00569        *  @param  first  An input iterator.
00570        *  @param  last   An input iterator.
00571        *
00572        *  This function fills a %list with copies of the elements in the
00573        *  range [@a first,@a last).
00574        *
00575        *  Note that the assignment completely changes the %list and
00576        *  that the resulting %list's size is the same as the number of
00577        *  elements assigned.  Old data may be lost.
00578        */
00579       template<typename _InputIterator>
00580         void
00581         assign(_InputIterator __first, _InputIterator __last)
00582         {
00583       // Check whether it's an integral type.  If so, it's not an iterator.
00584       typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
00585       _M_assign_dispatch(__first, __last, _Integral());
00586     }
00587
00588       /// Get a copy of the memory allocation object.
00589       allocator_type
00590       get_allocator() const
00591       { return _Base::get_allocator(); }
00592
00593       // iterators
00594       /**
00595        *  Returns a read/write iterator that points to the first element in the
00596        *  %list.  Iteration is done in ordinary element order.
00597        */
00598       iterator
00599       begin()
00600       { return this->_M_impl._M_node._M_next; }
00601
00602       /**
00603        *  Returns a read-only (constant) iterator that points to the
00604        *  first element in the %list.  Iteration is done in ordinary
00605        *  element order.
00606        */
00607       const_iterator
00608       begin() const
00609       { return this->_M_impl._M_node._M_next; }
00610
00611       /**
00612        *  Returns a read/write iterator that points one past the last
00613        *  element in the %list.  Iteration is done in ordinary element
00614        *  order.
00615        */
00616       iterator
00617       end() { return &this->_M_impl._M_node; }
00618
00619       /**
00620        *  Returns a read-only (constant) iterator that points one past
00621        *  the last element in the %list.  Iteration is done in ordinary
00622        *  element order.
00623        */
00624       const_iterator
00625       end() const
00626       { return &this->_M_impl._M_node; }
00627
00628       /**
00629        *  Returns a read/write reverse iterator that points to the last
00630        *  element in the %list.  Iteration is done in reverse element
00631        *  order.
00632        */
00633       reverse_iterator
00634       rbegin()
00635       { return reverse_iterator(end()); }
00636
00637       /**
00638        *  Returns a read-only (constant) reverse iterator that points to
00639        *  the last element in the %list.  Iteration is done in reverse
00640        *  element order.
00641        */
00642       const_reverse_iterator
00643       rbegin() const
00644       { return const_reverse_iterator(end()); }
00645
00646       /**
00647        *  Returns a read/write reverse iterator that points to one
00648        *  before the first element in the %list.  Iteration is done in
00649        *  reverse element order.
00650        */
00651       reverse_iterator
00652       rend()
00653       { return reverse_iterator(begin()); }
00654
00655       /**
00656        *  Returns a read-only (constant) reverse iterator that points to one
00657        *  before the first element in the %list.  Iteration is done in reverse
00658        *  element order.
00659        */
00660       const_reverse_iterator
00661       rend() const
00662       { return const_reverse_iterator(begin()); }
00663
00664       // [23.2.2.2] capacity
00665       /**
00666        *  Returns true if the %list is empty.  (Thus begin() would equal
00667        *  end().)
00668        */
00669       bool
00670       empty() const
00671       { return this->_M_impl._M_node._M_next == &this->_M_impl._M_node; }
00672
00673       /**  Returns the number of elements in the %list.  */
00674       size_type
00675       size() const
00676       { return std::distance(begin(), end()); }
00677
00678       /**  Returns the size() of the largest possible %list.  */
00679       size_type
00680       max_size() const
00681       { return size_type(-1); }
00682
00683       /**
00684        *  @brief Resizes the %list to the specified number of elements.
00685        *  @param new_size Number of elements the %list should contain.
00686        *  @param x Data with which new elements should be populated.
00687        *
00688        *  This function will %resize the %list to the specified number
00689        *  of elements.  If the number is smaller than the %list's
00690        *  current size the %list is truncated, otherwise the %list is
00691        *  extended and new elements are populated with given data.
00692        */
00693       void
00694       resize(size_type __new_size, const value_type& __x);
00695
00696       /**
00697        *  @brief  Resizes the %list to the specified number of elements.
00698        *  @param  new_size  Number of elements the %list should contain.
00699        *
00700        *  This function will resize the %list to the specified number of
00701        *  elements.  If the number is smaller than the %list's current
00702        *  size the %list is truncated, otherwise the %list is extended
00703        *  and new elements are default-constructed.
00704        */
00705       void
00706       resize(size_type __new_size)
00707       { this->resize(__new_size, value_type()); }
00708
00709       // element access
00710       /**
00711        *  Returns a read/write reference to the data at the first
00712        *  element of the %list.
00713        */
00714       reference
00715       front()
00716       { return *begin(); }
00717
00718       /**
00719        *  Returns a read-only (constant) reference to the data at the first
00720        *  element of the %list.
00721        */
00722       const_reference
00723       front() const
00724       { return *begin(); }
00725
00726       /**
00727        *  Returns a read/write reference to the data at the last element
00728        *  of the %list.
00729        */
00730       reference
00731       back()
00732       { return *(--end()); }
00733
00734       /**
00735        *  Returns a read-only (constant) reference to the data at the last
00736        *  element of the %list.
00737        */
00738       const_reference
00739       back() const
00740       { return *(--end()); }
00741
00742       // [23.2.2.3] modifiers
00743       /**
00744        *  @brief  Add data to the front of the %list.
00745        *  @param  x  Data to be added.
00746        *
00747        *  This is a typical stack operation.  The function creates an
00748        *  element at the front of the %list and assigns the given data
00749        *  to it.  Due to the nature of a %list this operation can be
00750        *  done in constant time, and does not invalidate iterators and
00751        *  references.
00752        */
00753       void
00754       push_front(const value_type& __x)
00755       { this->_M_insert(begin(), __x); }
00756
00757       /**
00758        *  @brief  Removes first element.
00759        *
00760        *  This is a typical stack operation.  It shrinks the %list by
00761        *  one.  Due to the nature of a %list this operation can be done
00762        *  in constant time, and only invalidates iterators/references to
00763        *  the element being removed.
00764        *
00765        *  Note that no data is returned, and if the first element's data
00766        *  is needed, it should be retrieved before pop_front() is
00767        *  called.
00768        */
00769       void
00770       pop_front()
00771       { this->_M_erase(begin()); }
00772
00773       /**
00774        *  @brief  Add data to the end of the %list.
00775        *  @param  x  Data to be added.
00776        *
00777        *  This is a typical stack operation.  The function creates an
00778        *  element at the end of the %list and assigns the given data to
00779        *  it.  Due to the nature of a %list this operation can be done
00780        *  in constant time, and does not invalidate iterators and
00781        *  references.
00782        */
00783       void
00784       push_back(const value_type& __x)
00785       { this->_M_insert(end(), __x); }
00786
00787       /**
00788        *  @brief  Removes last element.
00789        *
00790        *  This is a typical stack operation.  It shrinks the %list by
00791        *  one.  Due to the nature of a %list this operation can be done
00792        *  in constant time, and only invalidates iterators/references to
00793        *  the element being removed.
00794        *
00795        *  Note that no data is returned, and if the last element's data
00796        *  is needed, it should be retrieved before pop_back() is called.
00797        */
00798       void
00799       pop_back()
00800       { this->_M_erase(this->_M_impl._M_node._M_prev); }
00801
00802       /**
00803        *  @brief  Inserts given value into %list before specified iterator.
00804        *  @param  position  An iterator into the %list.
00805        *  @param  x  Data to be inserted.
00806        *  @return  An iterator that points to the inserted data.
00807        *
00808        *  This function will insert a copy of the given value before
00809        *  the specified location.  Due to the nature of a %list this
00810        *  operation can be done in constant time, and does not
00811        *  invalidate iterators and references.
00812        */
00813       iterator
00814       insert(iterator __position, const value_type& __x);
00815
00816       /**
00817        *  @brief  Inserts a number of copies of given data into the %list.
00818        *  @param  position  An iterator into the %list.
00819        *  @param  n  Number of elements to be inserted.
00820        *  @param  x  Data to be inserted.
00821        *
00822        *  This function will insert a specified number of copies of the
00823        *  given data before the location specified by @a position.
00824        *
00825        *  Due to the nature of a %list this operation can be done in
00826        *  constant time, and does not invalidate iterators and
00827        *  references.
00828        */
00829       void
00830       insert(iterator __position, size_type __n, const value_type& __x)
00831       { _M_fill_insert(__position, __n, __x); }
00832
00833       /**
00834        *  @brief  Inserts a range into the %list.
00835        *  @param  position  An iterator into the %list.
00836        *  @param  first  An input iterator.
00837        *  @param  last   An input iterator.
00838        *
00839        *  This function will insert copies of the data in the range [@a
00840        *  first,@a last) into the %list before the location specified by
00841        *  @a position.
00842        *
00843        *  Due to the nature of a %list this operation can be done in
00844        *  constant time, and does not invalidate iterators and
00845        *  references.
00846        */
00847       template<typename _InputIterator>
00848         void
00849         insert(iterator __position, _InputIterator __first,
00850            _InputIterator __last)
00851         {
00852       // Check whether it's an integral type.  If so, it's not an iterator.
00853       typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
00854       _M_insert_dispatch(__position, __first, __last, _Integral());
00855     }
00856
00857       /**
00858        *  @brief  Remove element at given position.
00859        *  @param  position  Iterator pointing to element to be erased.
00860        *  @return  An iterator pointing to the next element (or end()).
00861        *
00862        *  This function will erase the element at the given position and thus
00863        *  shorten the %list by one.
00864        *
00865        *  Due to the nature of a %list this operation can be done in
00866        *  constant time, and only invalidates iterators/references to
00867        *  the element being removed.  The user is also cautioned that
00868        *  this function only erases the element, and that if the element
00869        *  is itself a pointer, the pointed-to memory is not touched in
00870        *  any way.  Managing the pointer is the user's responsibilty.
00871        */
00872       iterator
00873       erase(iterator __position);
00874
00875       /**
00876        *  @brief  Remove a range of elements.
00877        *  @param  first  Iterator pointing to the first element to be erased.
00878        *  @param  last  Iterator pointing to one past the last element to be
00879        *                erased.
00880        *  @return  An iterator pointing to the element pointed to by @a last
00881        *           prior to erasing (or end()).
00882        *
00883        *  This function will erase the elements in the range @a
00884        *  [first,last) and shorten the %list accordingly.
00885        *
00886        *  Due to the nature of a %list this operation can be done in
00887        *  constant time, and only invalidates iterators/references to
00888        *  the element being removed.  The user is also cautioned that
00889        *  this function only erases the elements, and that if the
00890        *  elements themselves are pointers, the pointed-to memory is not
00891        *  touched in any way.  Managing the pointer is the user's
00892        *  responsibilty.
00893        */
00894       iterator
00895       erase(iterator __first, iterator __last)
00896       {
00897     while (__first != __last)
00898       __first = erase(__first);
00899     return __last;
00900       }
00901
00902       /**
00903        *  @brief  Swaps data with another %list.
00904        *  @param  x  A %list of the same element and allocator types.
00905        *
00906        *  This exchanges the elements between two lists in constant
00907        *  time.  Note that the global std::swap() function is
00908        *  specialized such that std::swap(l1,l2) will feed to this
00909        *  function.
00910        */
00911       void
00912       swap(list& __x)
00913       { _List_node_base::swap(this->_M_impl._M_node,__x._M_impl._M_node); }
00914
00915       /**
00916        *  Erases all the elements.  Note that this function only erases
00917        *  the elements, and that if the elements themselves are
00918        *  pointers, the pointed-to memory is not touched in any way.
00919        *  Managing the pointer is the user's responsibilty.
00920        */
00921       void
00922       clear()
00923       {
00924         _Base::_M_clear();
00925         _Base::_M_init();
00926       }
00927
00928       // [23.2.2.4] list operations
00929       /**
00930        *  @brief  Insert contents of another %list.
00931        *  @param  position  Iterator referencing the element to insert before.
00932        *  @param  x  Source list.
00933        *
00934        *  The elements of @a x are inserted in constant time in front of
00935        *  the element referenced by @a position.  @a x becomes an empty
00936        *  list.
00937        */
00938       void
00939       splice(iterator __position, list& __x)
00940       {
00941     if (!__x.empty())
00942       this->_M_transfer(__position, __x.begin(), __x.end());
00943       }
00944
00945       /**
00946        *  @brief  Insert element from another %list.
00947        *  @param  position  Iterator referencing the element to insert before.
00948        *  @param  x  Source list.
00949        *  @param  i  Iterator referencing the element to move.
00950        *
00951        *  Removes the element in list @a x referenced by @a i and
00952        *  inserts it into the current list before @a position.
00953        */
00954       void
00955       splice(iterator __position, list&, iterator __i)
00956       {
00957     iterator __j = __i;
00958     ++__j;
00959     if (__position == __i || __position == __j)
00960       return;
00961     this->_M_transfer(__position, __i, __j);
00962       }
00963
00964       /**
00965        *  @brief  Insert range from another %list.
00966        *  @param  position  Iterator referencing the element to insert before.
00967        *  @param  x  Source list.
00968        *  @param  first  Iterator referencing the start of range in x.
00969        *  @param  last  Iterator referencing the end of range in x.
00970        *
00971        *  Removes elements in the range [first,last) and inserts them
00972        *  before @a position in constant time.
00973        *
00974        *  Undefined if @a position is in [first,last).
00975        */
00976       void
00977       splice(iterator __position, list&, iterator __first, iterator __last)
00978       {
00979     if (__first != __last)
00980       this->_M_transfer(__position, __first, __last);
00981       }
00982
00983       /**
00984        *  @brief  Remove all elements equal to value.
00985        *  @param  value  The value to remove.
00986        *
00987        *  Removes every element in the list equal to @a value.
00988        *  Remaining elements stay in list order.  Note that this
00989        *  function only erases the elements, and that if the elements
00990        *  themselves are pointers, the pointed-to memory is not
00991        *  touched in any way.  Managing the pointer is the user's
00992        *  responsibilty.
00993        */
00994       void
00995       remove(const _Tp& __value);
00996
00997       /**
00998        *  @brief  Remove all elements satisfying a predicate.
00999        *  @param  Predicate  Unary predicate function or object.
01000        *
01001        *  Removes every element in the list for which the predicate
01002        *  returns true.  Remaining elements stay in list order.  Note
01003        *  that this function only erases the elements, and that if the
01004        *  elements themselves are pointers, the pointed-to memory is
01005        *  not touched in any way.  Managing the pointer is the user's
01006        *  responsibilty.
01007        */
01008       template<typename _Predicate>
01009       void
01010       remove_if(_Predicate);
01011
01012       /**
01013        *  @brief  Remove consecutive duplicate elements.
01014        *
01015        *  For each consecutive set of elements with the same value,
01016        *  remove all but the first one.  Remaining elements stay in
01017        *  list order.  Note that this function only erases the
01018        *  elements, and that if the elements themselves are pointers,
01019        *  the pointed-to memory is not touched in any way.  Managing
01020        *  the pointer is the user's responsibilty.
01021        */
01022       void
01023       unique();
01024
01025       /**
01026        *  @brief  Remove consecutive elements satisfying a predicate.
01027        *  @param  BinaryPredicate  Binary predicate function or object.
01028        *
01029        *  For each consecutive set of elements [first,last) that
01030        *  satisfy predicate(first,i) where i is an iterator in
01031        *  [first,last), remove all but the first one.  Remaining
01032        *  elements stay in list order.  Note that this function only
01033        *  erases the elements, and that if the elements themselves are
01034        *  pointers, the pointed-to memory is not touched in any way.
01035        *  Managing the pointer is the user's responsibilty.
01036        */
01037       template<typename _BinaryPredicate>
01038         void
01039         unique(_BinaryPredicate);
01040
01041       /**
01042        *  @brief  Merge sorted lists.
01043        *  @param  x  Sorted list to merge.
01044        *
01045        *  Assumes that both @a x and this list are sorted according to
01046        *  operator<().  Merges elements of @a x into this list in
01047        *  sorted order, leaving @a x empty when complete.  Elements in
01048        *  this list precede elements in @a x that are equal.
01049        */
01050       void
01051       merge(list& __x);
01052
01053       /**
01054        *  @brief  Merge sorted lists according to comparison function.
01055        *  @param  x  Sorted list to merge.
01056        *  @param StrictWeakOrdering Comparison function definining
01057        *  sort order.
01058        *
01059        *  Assumes that both @a x and this list are sorted according to
01060        *  StrictWeakOrdering.  Merges elements of @a x into this list
01061        *  in sorted order, leaving @a x empty when complete.  Elements
01062        *  in this list precede elements in @a x that are equivalent
01063        *  according to StrictWeakOrdering().
01064        */
01065       template<typename _StrictWeakOrdering>
01066         void
01067         merge(list&, _StrictWeakOrdering);
01068
01069       /**
01070        *  @brief  Reverse the elements in list.
01071        *
01072        *  Reverse the order of elements in the list in linear time.
01073        */
01074       void
01075       reverse()
01076       { this->_M_impl._M_node.reverse(); }
01077
01078       /**
01079        *  @brief  Sort the elements.
01080        *
01081        *  Sorts the elements of this list in NlogN time.  Equivalent
01082        *  elements remain in list order.
01083        */
01084       void
01085       sort();
01086
01087       /**
01088        *  @brief  Sort the elements according to comparison function.
01089        *
01090        *  Sorts the elements of this list in NlogN time.  Equivalent
01091        *  elements remain in list order.
01092        */
01093       template<typename _StrictWeakOrdering>
01094         void
01095         sort(_StrictWeakOrdering);
01096
01097     protected:
01098       // Internal assign functions follow.
01099
01100       // Called by the range assign to implement [23.1.1]/9
01101       template<typename _Integer>
01102         void
01103         _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
01104         {
01105       _M_fill_assign(static_cast<size_type>(__n),
01106              static_cast<value_type>(__val));
01107     }
01108
01109       // Called by the range assign to implement [23.1.1]/9
01110       template<typename _InputIterator>
01111         void
01112         _M_assign_dispatch(_InputIterator __first, _InputIterator __last,
01113                __false_type);
01114
01115       // Called by assign(n,t), and the range assign when it turns out
01116       // to be the same thing.
01117       void
01118       _M_fill_assign(size_type __n, const value_type& __val);
01119
01120
01121       // Internal insert functions follow.
01122
01123       // Called by the range insert to implement [23.1.1]/9
01124       template<typename _Integer>
01125         void
01126         _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __x,
01127                __true_type)
01128         {
01129       _M_fill_insert(__pos, static_cast<size_type>(__n),
01130              static_cast<value_type>(__x));
01131     }
01132
01133       // Called by the range insert to implement [23.1.1]/9
01134       template<typename _InputIterator>
01135         void
01136         _M_insert_dispatch(iterator __pos,
01137                _InputIterator __first, _InputIterator __last,
01138                __false_type)
01139         {
01140       for ( ; __first != __last; ++__first)
01141         _M_insert(__pos, *__first);
01142     }
01143
01144       // Called by insert(p,n,x), and the range insert when it turns out
01145       // to be the same thing.
01146       void
01147       _M_fill_insert(iterator __pos, size_type __n, const value_type& __x)
01148       {
01149     for ( ; __n > 0; --__n)
01150       _M_insert(__pos, __x);
01151       }
01152
01153
01154       // Moves the elements from [first,last) before position.
01155       void
01156       _M_transfer(iterator __position, iterator __first, iterator __last)
01157       { __position._M_node->transfer(__first._M_node,__last._M_node); }
01158
01159       // Inserts new element at position given and with value given.
01160       void
01161       _M_insert(iterator __position, const value_type& __x)
01162       {
01163         _Node* __tmp = _M_create_node(__x);
01164         __tmp->hook(__position._M_node);
01165       }
01166
01167       // Erases element at position given.
01168       void
01169       _M_erase(iterator __position)
01170       {
01171         __position._M_node->unhook();
01172         _Node* __n = static_cast<_Node*>(__position._M_node);
01173         std::_Destroy(&__n->_M_data);
01174         _M_put_node(__n);
01175       }
01176     };
01177
01178   /**
01179    *  @brief  List equality comparison.
01180    *  @param  x  A %list.
01181    *  @param  y  A %list of the same type as @a x.
01182    *  @return  True iff the size and elements of the lists are equal.
01183    *
01184    *  This is an equivalence relation.  It is linear in the size of
01185    *  the lists.  Lists are considered equivalent if their sizes are
01186    *  equal, and if corresponding elements compare equal.
01187   */
01188   template<typename _Tp, typename _Alloc>
01189     inline bool
01190     operator==(const list<_Tp,_Alloc>& __x, const list<_Tp,_Alloc>& __y)
01191     {
01192       typedef typename list<_Tp,_Alloc>::const_iterator const_iterator;
01193       const_iterator __end1 = __x.end();
01194       const_iterator __end2 = __y.end();
01195
01196       const_iterator __i1 = __x.begin();
01197       const_iterator __i2 = __y.begin();
01198       while (__i1 != __end1 && __i2 != __end2 && *__i1 == *__i2)
01199     {
01200       ++__i1;
01201       ++__i2;
01202     }
01203       return __i1 == __end1 && __i2 == __end2;
01204     }
01205
01206   /**
01207    *  @brief  List ordering relation.
01208    *  @param  x  A %list.
01209    *  @param  y  A %list of the same type as @a x.
01210    *  @return  True iff @a x is lexicographically less than @a y.
01211    *
01212    *  This is a total ordering relation.  It is linear in the size of the
01213    *  lists.  The elements must be comparable with @c <.
01214    *
01215    *  See std::lexicographical_compare() for how the determination is made.
01216   */
01217   template<typename _Tp, typename _Alloc>
01218     inline bool
01219     operator<(const list<_Tp,_Alloc>& __x, const list<_Tp,_Alloc>& __y)
01220     { return std::lexicographical_compare(__x.begin(), __x.end(),
01221                       __y.begin(), __y.end()); }
01222
01223   /// Based on operator==
01224   template<typename _Tp, typename _Alloc>
01225     inline bool
01226     operator!=(const list<_Tp,_Alloc>& __x, const list<_Tp,_Alloc>& __y)
01227     { return !(__x == __y); }
01228
01229   /// Based on operator<
01230   template<typename _Tp, typename _Alloc>
01231     inline bool
01232     operator>(const list<_Tp,_Alloc>& __x, const list<_Tp,_Alloc>& __y)
01233     { return __y < __x; }
01234
01235   /// Based on operator<
01236   template<typename _Tp, typename _Alloc>
01237     inline bool
01238     operator<=(const list<_Tp,_Alloc>& __x, const list<_Tp,_Alloc>& __y)
01239     { return !(__y < __x); }
01240
01241   /// Based on operator<
01242   template<typename _Tp, typename _Alloc>
01243     inline bool
01244     operator>=(const list<_Tp,_Alloc>& __x, const list<_Tp,_Alloc>& __y)
01245     { return !(__x < __y); }
01246
01247   /// See std::list::swap().
01248   template<typename _Tp, typename _Alloc>
01249     inline void
01250     swap(list<_Tp, _Alloc>& __x, list<_Tp, _Alloc>& __y)
01251     { __x.swap(__y); }
01252 } // namespace std
01253
01254 #endif /* _LIST_H */
01255

Generated on Fri May 6 01:09:09 2005 for libstdc++-v3 Source by  doxygen 1.4.2
