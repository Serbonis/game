#pragma once
//========================================
// actor_c.hpp
//========================================
#include "com.hpp"

//----------------------------------------
// ACTOR_C
//----------------------------------------
class ACTOR_X;
template<typename... TYPE>class ACTOR_C : public TYPE... {
private:
	explicit ACTOR_C() = delete;

public:
	explicit ACTOR_C( ACTOR_X* a ) : TYPE{a}...{}
	virtual ~ACTOR_C() = default;

private:
    template<class TUPLE, std::size_t...INDEX>void updater( ACTOR_X* a, const TUPLE*, std::index_sequence<INDEX...>){
        using EXPANSION = int[];

        ( void )EXPANSION{ ( std::tuple_element_t<INDEX,TUPLE>::Updater( a ) , 0 )... };
    };

public:
    virtual void Updater( ACTOR_X* a ) final {
		using TYPE_PACK = std::tuple<TYPE...>;

		updater( a, ( TYPE_PACK* )nullptr, std::make_index_sequence<std::tuple_size_v<TYPE_PACK>>{});
	}
};

template<>class ACTOR_C<> {
private:
	explicit ACTOR_C() = delete;

public:
	explicit ACTOR_C( ACTOR_X* a ){}
	virtual ~ACTOR_C() = default;

    virtual void Updater( ACTOR_X* a ) final {}
};

// End Of File
