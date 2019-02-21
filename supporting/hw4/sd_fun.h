#ifndef _SD_FUN_
#include<cstddef>
#include<cstdlib>

struct Range {
  int pos, len;
};
const int max_length = 10000;

class irange {
private:
	int last, curr;

public:
	irange(int end): last(end), curr(0) {}

	const irange& begin() const { return *this; }
	const irange& end() const { return *this; }

	bool operator!=(const irange&) const { return curr < last; }
	void operator++() { ++curr; }
	int operator*() const { return curr; }
};

// from sd_fun.cpp
extern void initialize(char *&mem, char *&yaml);
extern void initialize_empty(char *&mem, char *&yaml);
extern void initialize_from_file(const char *fname, char *&mem, char *&yaml);
extern void terminate(const char *buffer, const char *yaml);
extern char *query_data_port(const char *query);
extern void read_file_into_mem(const char *fname, char *mem, int start = 0);

extern long long current_time();
extern const char *time_of_day(const char *ms);
extern double random_number();

// from str_util.cpp
extern int length_of(const char *s, int pos=0);
extern int indentation_at(const char *response, int pos);
extern int indentation_of(const char *response, int pos);
extern void print_range(const char *s, Range r);

extern void append(char *s, const char *t);
extern void append(char *s, int n);
extern void append(char *s, const char *t, Range r);
extern void append(char *s, long long n);

extern void append(char *s, const char *pre, const char *t, const char *post="");
extern void append(char *s, const char *pre, int n, const char *post="");
extern void append(char *s, const char *pre, const char *t, Range r, const char *post="");

extern int index_of(const char *s, Range &r, const char *query);
extern int index_of(const char *s, int start, const char *query);
extern int index_of(const char *s, const char *query);

extern bool in(const char *s, const char *query);
extern bool in(const char *s, int start, const char *query);
extern bool in(const char *s, Range r, const char *query);
extern bool was_pressed(const char *s, const char *query);

extern int count(const char *s, Range r, const char *query);
extern int count(const char *s, int start, const char *query);
extern int count(const char *s, const char *query);

extern void write_chars_at(char *mem, int pos, char c0, char c1=-1, char c2=-1, char c3=-1, char c4=-1, char c5=-1, char c6=-1, char c7=-1, char c8=-1, char c9=-1, char c10=-1, char c11=-1, char c12=-1, char c13=-1, char c14=-1, char c15=-1, char c16=-1, char c17=-1, char c18=-1, char c19=-1);
extern void write_at(char *mem, int pos, const char *x);
extern void write_at(char *mem, int pos, bool t);
extern void write_at(char *mem, int pos, int n);
extern void write_at(char *mem, int pos, std::size_t n);
extern void write_at(char *mem, int pos, double d);
extern void write_at(char *mem, int pos, const char *x, Range r);
extern void write_at(char *mem, int pos, const char *x, int start);

extern bool is_whitespace(char c);
extern bool is_whitespace_or_char(char c, const char *chars = "");
extern Range split(char *mem, Range &r, const char *sep="");
extern Range split(char *mem, int &start, const char *sep="");

extern void lstrip(const char *yaml, Range &r, const char *chars = "");
extern void rstrip(const char *yaml, Range &r, const char *chars = "");
extern void strip(const char *yaml, Range &r, const char *chars = "");

extern Range find_value(const char *yaml, Range &r, const char *key, bool skip_quotes = true);
extern Range find_value(const char *yaml, int &start, const char *key, bool skip_quotes = true);
extern Range find_value(const char *yaml, const char *key, bool skip_quotes);

extern int as_integer(const char *yaml, int pos);

#endif // _SD_FUN_
