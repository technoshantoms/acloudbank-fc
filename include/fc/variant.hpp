#pragma once 

#include <array>
#include <cstddef>
#include <deque>
#include <map>
#include <memory>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <string.h> // memset

#include <fc/optional.hpp>
#include <fc/uint128.hpp>
#include <fc/container/flat_fwd.hpp>
#include <fc/crypto/hex.hpp>
#include <boost/endian/buffers.hpp>
#include <boost/multi_index_container_fwd.hpp>

#ifdef FC_ASSERT
#define _FC_ASSERT(...) FC_ASSERT( __VA_ARGS__ )
#else
// poor man's FC_ASSERT, want to avoid recursive inclusion of exception.hpp
namespace fc
{
void throw_assertion_failure( const std::string& message );
}
#define _FC_ASSERT( cond, msg ) { if( !(cond) ) { char t[] = #cond ": " msg; fc::throw_assertion_failure( t ); } }
#endif

namespace fc
{
   /**
    * @defgroup serializable Serializable _types
    * @brief Classes that may be converted to/from an variant
    *
    * To make a class 'serializable' the following methods must be available 
    * for your Serializable_type
    *
    *  @code 
    *     void   to_variant( const Serializable_type& e, variant& v, uint32_t max_depth );
    *     void   from_variant( const variant& e, Serializable_type& ll, uint32_t max_depth );
    *  @endcode
    */

   class variant;
   class variant_object;
   class mutable_variant_object;
   class time_point;
   class time_point_sec;
   class microseconds;
   template<typename T> struct safe;
   template<typename... Types>
   class static_variant;

   struct blob { std::vector<char> data; };

   void to_variant( const blob& var, variant& vo, uint32_t max_depth = 1);
   void from_variant( const variant& var, blob& vo, uint32_t max_depth = 1 );


   template<typename T, typename... Args> void to_variant( const boost::multi_index_container<T,Args...>& s, variant& v, uint32_t max_depth );
   template<typename T, typename... Args> void from_variant( const variant& v, boost::multi_index_container<T,Args...>& s, uint32_t max_depth );

   template<typename T> void to_variant( const safe<T>& s, variant& v, uint32_t max_depth );
   template<typename T> void from_variant( const variant& v, safe<T>& s, uint32_t max_depth );
   template<typename T> void to_variant( const std::unique_ptr<T>& s, variant& v, uint32_t max_depth );
   template<typename T> void from_variant( const variant& v, std::unique_ptr<T>& s, uint32_t max_depth );

   template<typename... T> void to_variant( const static_variant<T...>& s, variant& v, uint32_t max_depth );
   template<typename... T> void from_variant( const variant& v, static_variant<T...>& s, uint32_t max_depth );

   void to_variant( const uint8_t& var,   variant& vo, uint32_t max_depth = 1 );
   void from_variant( const variant& var, uint8_t& vo, uint32_t max_depth = 1 );
   void to_variant( const int8_t& var,    variant& vo, uint32_t max_depth = 1 );
   void from_variant( const variant& var, int8_t& vo,  uint32_t max_depth = 1 );

   void to_variant( const uint16_t& var,  variant& vo,  uint32_t max_depth = 1 );
   void from_variant( const variant& var, uint16_t& vo, uint32_t max_depth = 1 );
   void to_variant( const int16_t& var,   variant& vo,  uint32_t max_depth = 1 );
   void from_variant( const variant& var, int16_t& vo,  uint32_t max_depth = 1 );

   void to_variant( const uint32_t& var,  variant& vo,  uint32_t max_depth = 1 );
   /** @ingroup Serializable */
   void from_variant( const variant& var, uint32_t& vo, uint32_t max_depth = 1 );
   void to_variant( const int32_t& var,   variant& vo,  uint32_t max_depth = 1 );
   /** @ingroup Serializable */
   void from_variant( const variant& var, int32_t& vo,  uint32_t max_depth = 1 );

   void to_variant( const uint64_t& var,  variant& vo,  uint32_t max_depth = 1 );
   void to_variant( const int64_t& var,   variant& vo,  uint32_t max_depth = 1 );

   void to_variant( const bool& var,      variant& vo,  uint32_t max_depth = 1 );

   void to_variant( const variant_object& var, variant& vo,        uint32_t max_depth );
   void from_variant( const variant& var,      variant_object& vo, uint32_t max_depth );
   void to_variant( const mutable_variant_object& var, variant& vo,   uint32_t max_depth );
   void from_variant( const variant& var, mutable_variant_object& vo, uint32_t max_depth );
   void to_variant( const std::vector<char>& var, variant& vo,   uint32_t max_depth = 1 );
   void from_variant( const variant& var, std::vector<char>& vo, uint32_t max_depth = 1 );

   template<typename K, typename T>
   void to_variant( const std::unordered_map<K,T>& var, variant& vo,   uint32_t max_depth );
   template<typename K, typename T>
   void from_variant( const variant& var, std::unordered_map<K,T>& vo, uint32_t max_depth );

   template<typename K, typename... T>
   void to_variant( const fc::flat_map<K,T...>& var,  variant& vo, uint32_t max_depth );
   template<typename K, typename T, typename... A>
   void from_variant(const variant& var, flat_map<K, T, A...>& vo, uint32_t max_depth );

   template<typename K, typename... T>
   void to_variant( const std::map<K, T...>& var,   variant& vo, uint32_t max_depth );
   template<typename K, typename T, typename... A>
   void from_variant( const variant& var, std::map<K, T, A...>& vo, uint32_t max_depth );
   template<typename K, typename T>
   void to_variant( const std::multimap<K,T>& var,   variant& vo, uint32_t max_depth );
   template<typename K, typename T>
   void from_variant( const variant& var, std::multimap<K,T>& vo, uint32_t max_depth );


   template<typename T>
   void to_variant( const std::unordered_set<T>& var,   variant& vo, uint32_t max_depth );
   template<typename T>
   void from_variant( const variant& var, std::unordered_set<T>& vo, uint32_t max_depth );

   template<typename T>
   void to_variant( const std::deque<T>& var,   variant& vo, uint32_t max_depth );
   template<typename T>
   void from_variant( const variant& var, std::deque<T>& vo, uint32_t max_depth );

   template<typename T, typename... A>
   void to_variant( const fc::flat_set<T, A...>& var,   variant& vo, uint32_t max_depth );
   template<typename T, typename... A>
   void from_variant( const variant& var, fc::flat_set<T, A...>& vo, uint32_t max_depth );

   template<typename T>
   void to_variant( const std::set<T>& var,  variant& vo,  uint32_t max_depth );
   template<typename T>
   void from_variant( const variant& var, std::set<T>& vo, uint32_t max_depth );

   void to_variant( const time_point& var,   variant& vo, uint32_t max_depth );
   void from_variant( const variant& var, time_point& vo, uint32_t max_depth );

   void to_variant( const time_point_sec& var,   variant& vo, uint32_t max_depth );
   void from_variant( const variant& var, time_point_sec& vo, uint32_t max_depth );

   void to_variant( const microseconds& input_microseconds,   variant& output_variant, uint32_t max_depth );
   void from_variant( const variant& input_variant, microseconds& output_microseconds, uint32_t max_depth );

   void to_variant( const uint128_t& var, variant& vo, uint32_t max_depth = 1 );
   void from_variant( const variant& var, uint128_t& vo, uint32_t max_depth = 1 );

   #if defined(__APPLE__) or defined(__OpenBSD__)
   void to_variant( size_t s, variant& v, uint32_t max_depth = 1 );
   #elif !defined(_WIN32)
   void to_variant( long long int s,          variant& v, uint32_t max_depth = 1 );
   void to_variant( unsigned long long int s, variant& v, uint32_t max_depth = 1 );
   #endif
   void to_variant( const std::string& s, variant& v, uint32_t max_depth = 1 );

   template<typename T>
   void to_variant( const std::shared_ptr<T>& var,   variant& vo, uint32_t max_depth );

   template<typename T>
   void from_variant( const variant& var, std::shared_ptr<T>& vo, uint32_t max_depth );

   typedef std::vector<variant>   variants;
   template<typename A, typename B>
   void to_variant( const std::pair<A,B>& t,   variant& v, uint32_t max_depth );
   template<typename A, typename B>
   void from_variant( const variant& v, std::pair<A,B>& p, uint32_t max_depth );

   template<boost::endian::order O, class T, std::size_t N, boost::endian::align A>
   void to_variant( const boost::endian::endian_buffer<O,T,N,A>& var, variant& vo,  uint32_t max_depth )
   {
      to_variant( var.value(), vo, max_depth );
   }
   template<boost::endian::order O, class T, std::size_t N, boost::endian::align A>
   void from_variant( const variant& var, boost::endian::endian_buffer<O,T,N,A>& vo, uint32_t max_depth )
   {
      T tmp;
      from_variant( var, tmp, max_depth );
      vo = tmp;
   }

   /**
    * @brief stores null, int64, uint64, double, bool, string, std::vector<variant>,
    *        and variant_object's.  
    *
    * variant's allocate everything but strings, arrays, and objects on the
    * stack and are 'move aware' for values allocated on the heap.
    *
    * Memory usage on 64 bit systems is 16 bytes and 12 bytes on 32 bit systems.
    */
   class variant
   {
      public:
        enum type_id
        {
           null_type   = 0,     
           int64_type  = 1, 
           uint64_type = 2, 
           double_type = 3,
           bool_type   = 4,
           string_type = 5,
           array_type  = 6,
           object_type = 7,
           blob_type   = 8
        };

        /// Constructs a null_type variant
        variant();
        /// Constructs a null_type variant
        variant( std::nullptr_t, uint32_t max_depth = 1 );

        /// @param str - UTF8 string
        /// @param max_depth - the maximum depth to recurse into
        variant( const char* str, uint32_t max_depth = 1 );
        variant( char* str, uint32_t max_depth = 1 );
        variant( wchar_t* str, uint32_t max_depth = 1 );
        variant( const wchar_t* str, uint32_t max_depth = 1 );
        variant( float val, uint32_t max_depth = 1 );
        variant( uint8_t val, uint32_t max_depth = 1 );
        variant( int8_t val, uint32_t max_depth = 1 );
        variant( uint16_t val, uint32_t max_depth = 1 );
        variant( int16_t val, uint32_t max_depth = 1 );
        variant( uint32_t val, uint32_t max_depth = 1 );
        variant( int32_t val, uint32_t max_depth = 1 );
        variant( uint64_t val, uint32_t max_depth = 1 );
#if defined(__APPLE__) or defined(__OpenBSD__)
        variant( size_t val, uint32_t max_depth = 1 );
#endif
        variant( int64_t val, uint32_t max_depth = 1 );
        variant( double val, uint32_t max_depth = 1 );
        variant( bool val, uint32_t max_depth = 1 );
        variant( blob val, uint32_t max_depth = 1 );
        variant( std::string val, uint32_t max_depth = 1 );
        variant( variant_object, uint32_t max_depth = 1 );
        variant( mutable_variant_object, uint32_t max_depth = 1 );
        variant( variants, uint32_t max_depth = 1 );
        variant( const variant&, uint32_t max_depth = 1 );
        variant( variant&&, uint32_t max_depth = 1 );
       ~variant();

        /**
         *  Read-only access to the content of the variant.
         */
        class visitor 
        {
           public:
              virtual ~visitor(){}
              /// handles null_type variants
              virtual void handle()const                         = 0;
              virtual void handle( const int64_t& v )const       = 0;
              virtual void handle( const uint64_t& v )const      = 0;
              virtual void handle( const double& v )const        = 0;
              virtual void handle( const bool& v )const          = 0;
              virtual void handle( const std::string& v )const   = 0;
              virtual void handle( const variant_object& v)const = 0;
              virtual void handle( const variants& v)const       = 0;
        };

        void  visit( const visitor& v )const;

        type_id                     get_type()const;

        bool                        is_null()const;
        bool                        is_string()const;
        bool                        is_bool()const;
        bool                        is_int64()const;
        bool                        is_uint64()const;
        bool                        is_double()const;
        bool                        is_object()const;
        bool                        is_array()const;
        bool                        is_blob()const;
        /**
         *   int64, uint64, double,bool
         */
        bool                        is_numeric()const;
        /**
         *   int64, uint64, bool
         */
        bool                        is_integer()const;
                                    
        int64_t                     as_int64()const;
        uint64_t                    as_uint64()const;
        bool                        as_bool()const;
        double                      as_double()const;

        blob&                       get_blob();
        const blob&                 get_blob()const;
        blob                        as_blob()const;

        /** Convert's double, ints, bools, etc to a string
         * @throw if get_type() == array_type | get_type() == object_type 
         */
        std::string                 as_string()const;

        /// @pre  get_type() == string_type
        const std::string&          get_string()const;
                                    
        /// @throw if get_type() != array_type | null_type
        variants&                   get_array();

        /// @throw if get_type() != array_type 
        const variants&             get_array()const;

        /// @throw if get_type() != object_type | null_type
        variant_object&             get_object();

        /// @throw if get_type() != object_type 
        const variant_object&       get_object()const;

        /// @pre is_object()
        const variant&              operator[]( const char* )const;
        /// @pre is_array()
        const variant&              operator[]( size_t pos )const;
        /// @pre is_array()
        size_t                      size()const;

        /**
         *  _types that use non-intrusive variant conversion can implement the
         *  following method to implement conversion from variant to T.
         *
         *  <code>
         *  void from_variant( const Variant& var, T& val, uint32_t max_depth )
         *  </code>
         *
         *  The above form is not always convienant, so the this templated 
         *  method is used to enable conversion from Variants to other
         *  types.
         */
        template<typename T>
        T as( uint32_t max_depth )const
        {
           T tmp;
           from_variant( *this, tmp, max_depth );
           return tmp;
        }

        template<typename T>
        void as( T& v, uint32_t max_depth )const
        {
           from_variant( *this, v, max_depth );
        }

        variant& operator=( variant&& v );
        variant& operator=( const variant& v );

        template<typename T>
        variant& operator=( T&& v )
        {
           return *this = variant( std::forward<T>(v), FC_PACK_MAX_DEPTH );
        }

        template<typename T>
        variant( const optional<T>& v, uint32_t max_depth )
        {
           _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
           memset( this, 0, sizeof(*this) );
           if( v.valid() ) *this = variant( *v, max_depth - 1 );
        }

        template<typename T>
        variant( const T& val, uint32_t max_depth );


        void    clear();
      private:
        void    init();
        double  _data;                ///< Aligned according to double requirements
        char    _type[sizeof(void*)]; ///< pad to void* size
   };
   typedef optional<variant> ovariant;
  
   /** @ingroup Serializable */
   void from_variant( const variant& var,  std::string& vo, uint32_t max_depth = 1 );
   /** @ingroup Serializable */
   void from_variant( const variant& var,  variants& vo, uint32_t max_depth );
   void from_variant( const variant& var,  variant& vo,  uint32_t max_depth );
   /** @ingroup Serializable */
   void from_variant( const variant& var,  int64_t& vo,  uint32_t max_depth = 1 );
   /** @ingroup Serializable */
   void from_variant( const variant& var,  uint64_t& vo, uint32_t max_depth = 1 );
   /** @ingroup Serializable */
   void from_variant( const variant& var,  bool& vo,     uint32_t max_depth = 1 );
   /** @ingroup Serializable */
   void from_variant( const variant& var,  double& vo,   uint32_t max_depth = 1 );
   /** @ingroup Serializable */
   void from_variant( const variant& var,  float& vo,    uint32_t max_depth = 1 );
   /** @ingroup Serializable */
   template<typename T>
   void from_variant( const variant& var, optional<T>& vo, uint32_t max_depth )
   {
      if( var.is_null() ) vo = optional<T>();
      else
      {
          _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
          vo = T();
          from_variant( var, *vo, max_depth - 1 );
      }
   }
   template<typename T>
   void to_variant( const std::unordered_set<T>& var, variant& vo, uint32_t max_depth )
   {
       _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
       std::vector<variant> vars(var.size());
       size_t i = 0;
       for( const auto& item : var )
          vars[i++] = variant( item, max_depth - 1 );
       vo = vars;
   }
   template<typename T>
   void from_variant( const variant& var, std::unordered_set<T>& vo, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      const variants& vars = var.get_array();
      vo.clear();
      vo.reserve( vars.size() );
      for( const auto& item : vars )
         vo.insert( item.as<T>( max_depth - 1 ) );
   }


   template<typename K, typename T>
   void to_variant( const std::unordered_map<K, T>& var, variant& vo, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      std::vector< variant > vars(var.size());
      size_t i = 0;
      for( const auto& key_value : var )
         vars[i++] = fc::variant( key_value, max_depth - 1 );
      vo = vars;
   }
   template<typename K, typename T>
   void from_variant( const variant& var, std::unordered_map<K, T>& vo, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      const variants& vars = var.get_array();
      vo.clear();
      vo.reserve( vars.size() );
      for( const auto& item : vars )
         vo.insert( item.as< std::pair<K,T> >( max_depth - 1 ) );
   }
   template<typename K, typename... T>
   void to_variant( const std::map<K, T...>& var, variant& vo, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      std::vector< variant > vars(var.size());
      size_t i = 0;
      for( const auto& key_value : var )
         vars[i++] = fc::variant( key_value, max_depth - 1 );
      vo = vars;
   }
   template<typename K, typename T, typename... A>
   void from_variant( const variant& var, std::map<K, T, A...>& vo, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      const variants& vars = var.get_array();
      vo.clear();
      for( const auto& item : vars )
         vo.insert( item.as< std::pair<K,T> >( max_depth - 1 ) );
   }

   template<typename K, typename T>
   void to_variant( const std::multimap<K, T>& var, variant& vo, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      std::vector< variant > vars(var.size());
      size_t i = 0;
      for( const auto& key_value : var )
         vars[i++] = fc::variant( key_value, max_depth - 1 );
      vo = vars;
   }
   template<typename K, typename T>
   void from_variant( const variant& var, std::multimap<K, T>& vo, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      const variants& vars = var.get_array();
      vo.clear();
      for( auto item : vars )
         vo.insert( item.as< std::pair<K,T> >( max_depth - 1 ) );
   }


   template<typename T>
   void to_variant( const std::set<T>& var, variant& vo, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      std::vector<variant> vars(var.size());
      size_t i = 0;
      for( const auto& item : var )
         vars[i++] = fc::variant( item, max_depth - 1 );
      vo = vars;
   }
   template<typename T>
   void from_variant( const variant& var, std::set<T>& vo, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      const variants& vars = var.get_array();
      vo.clear();
      for( const auto& item : vars )
         vo.insert( item.as<T>( max_depth - 1 ) );
   }

   /** @ingroup Serializable */
   template<typename T>
   void from_variant( const variant& var, std::deque<T>& dest, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      const variants& vars = var.get_array();
      dest.clear();
      dest.resize( vars.size() );
      for( const auto& item : vars )
         dest.push_back( item.as<T>( max_depth - 1 ) );
   }

   /** @ingroup Serializable */
   template<typename T>
   void to_variant( const std::deque<T>& src, variant& v, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      std::vector<variant> vars(src.size());
      for( size_t i = 0; i < src.size(); ++i )
         vars[i] = variant( src[i], max_depth - 1 );
      v = std::move(vars);
   }


   /** @ingroup Serializable */
   template<typename T>
   void from_variant( const variant& var, std::vector<T>& dest, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      const variants& vars = var.get_array();
      dest.clear();
      dest.reserve( vars.size() );
      for( const auto& item : vars )
         dest.push_back( item.as<T>( max_depth - 1 ) );
   }

   /** @ingroup Serializable */
   template<typename T>
   void to_variant( const std::vector<T>& t, variant& v, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      std::vector<variant> vars(t.size());
      for( size_t i = 0; i < t.size(); ++i )
         vars[i] = variant( t[i], max_depth - 1 );
      v = std::move(vars);
   }


   /** @ingroup Serializable */
   template<typename A, typename B>
   void to_variant( const std::pair<A,B>& t, variant& v, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      std::vector<variant> vars(2);
      vars[0] = variant( t.first, max_depth - 1 );
      vars[1] = variant( t.second, max_depth - 1 );
      v = vars;
   }
   template<typename A, typename B>
   void from_variant( const variant& v, std::pair<A,B>& p, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      const variants& vars = v.get_array();
      if( vars.size() > 0 )
         p.first  = vars[0].as<A>( max_depth - 1 );
      if( vars.size() > 1 )
         p.second = vars[1].as<B>( max_depth - 1 );
   }


   template<typename T>
   variant::variant( const T& val, uint32_t max_depth )
   {
      memset( this, 0, sizeof(*this) );
      to_variant( val, *this, max_depth );
   }

   template<typename T>
   void to_variant( const std::shared_ptr<T>& var, variant& vo, uint32_t max_depth )
   {
      if( var )
      {
         _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
         to_variant( *var, vo, max_depth - 1 );
      }
      else vo = nullptr;
   }

   template<typename T>
   void from_variant( const variant& var, std::shared_ptr<T>& vo, uint32_t max_depth )
   {
      if( var.is_null() ) vo = nullptr;
      else
      {
         _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
         if( !vo ) vo = std::make_shared<T>();
         from_variant( var, *vo, max_depth - 1 );
      }
   }
   template<typename T>
   void to_variant( const std::unique_ptr<T>& var, variant& vo, uint32_t max_depth )
   {
      if( var )
      {
         _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
         to_variant( *var, vo, max_depth - 1 );
      }
      else vo = nullptr;
   }

   template<typename T>
   void from_variant( const variant& var, std::unique_ptr<T>& vo, uint32_t max_depth )
   {
      if( var.is_null() ) vo.reset();
      else
      {
         _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
         if( !vo ) vo.reset( new T() );
         from_variant( var, *vo, max_depth - 1 );
      }
   }


   template<typename T>
   void to_variant( const safe<T>& s, variant& v, uint32_t max_depth ) {
      to_variant( static_cast<T>(s.value), v, max_depth );
   }

   template<typename T>
   void from_variant( const variant& v, safe<T>& s, uint32_t max_depth ) {
      s.value = v.as<T>( max_depth );
   }

   template<typename T, typename... Args>
   void to_variant( const boost::multi_index_container<T,Args...>& c, variant& v, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      std::vector<variant> vars;
      vars.reserve( c.size() );
      for( const auto& item : c )
         vars.emplace_back( variant( item, max_depth - 1 ) );
      v = std::move(vars);
   }

   template<typename T, typename... Args>
   void from_variant( const variant& v, boost::multi_index_container<T,Args...>& c, uint32_t max_depth )
   {
      _FC_ASSERT( max_depth > 0, "Recursion depth exceeded!" );
      const variants& vars = v.get_array();
      c.clear();
      for( const auto& item : vars )
         c.insert( item.as<T>( max_depth - 1 ) );
   }

   template<size_t N>
   void to_variant( const std::array<char,N>& bi, variant& v, uint32_t max_depth = 1 )
   {
      v = variant( to_hex( bi.data(), N ) );
   }
   template<size_t N>
   void from_variant( const variant& v, std::array<char,N>& bi, uint32_t max_depth = 1 )
   {
      std::string ve = v.as_string();
      if( ve.size() )
         from_hex( ve, bi.data(), std::min<size_t>( ve.size() / 2, bi.size() ) );
      else
         memset( bi.data(), 0, bi.size() );
   }

   template<size_t N>
   void to_variant( const std::array<unsigned char,N>& bi, variant& v, uint32_t max_depth = 1 )
   {
      v = variant( to_hex( (char*) bi.data(), N ) );
   }
   template<size_t N>
   void from_variant( const variant& v, std::array<unsigned char,N>& bi, uint32_t max_depth = 1 )
   {
      std::string ve = v.as_string();
      if( ve.size() )
         from_hex( ve, (char*)bi.data(), std::min<size_t>( ve.size() / 2, bi.size() ) );
      else
         memset( bi.data(), 0, bi.size() );
   }

   variant operator + ( const variant& a, const variant& b );
   variant operator - ( const variant& a, const variant& b );
   variant operator * ( const variant& a, const variant& b );
   variant operator / ( const variant& a, const variant& b );
   bool    operator == ( const variant& a, const variant& b );
   bool    operator != ( const variant& a, const variant& b );
   bool    operator < ( const variant& a, const variant& b );
   bool    operator > ( const variant& a, const variant& b );
   bool    operator ! ( const variant& a );
} // namespace fc

#include <fc/reflect/reflect.hpp>
FC_REFLECT_TYPENAME( fc::variant )
FC_REFLECT_ENUM( fc::variant::type_id, (null_type)(int64_type)(uint64_type)(double_type)(bool_type)(string_type)(array_type)(object_type)(blob_type) )
FC_REFLECT( fc::blob, (data) )
