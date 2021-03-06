/*
 *  TestCollection.h
 *  mom
 *
 *  Created by Nathaniel Thurston on 27/09/2007.
 *  Copyright 2007 THingith ehf.. All rights reserved.
 *
 */

#include <map>
#include <string>
#include <vector>
#include "Params.h"
#include "Box.h"

typedef enum _box_state
{
killed_bounds = 9,
killed_no_parabolics = 1,
killed_identity_impossible = 3,
killed_parabolics_impossible = 8,
killed_bad_parabolic = 4,
killed_elliptic = 5,
killed_failed_qr = 2,
open_with_qr = 6,
variety_nbd = 7,
variety_center = 10,
large_horoball_center = 11,
out_of_bounds_center = 12,
open = -1
} 
box_state;

struct ImpossibleRelations;

struct TestCollection {
	int size();
	box_state evaluateCenter(int index, Box& box);
	box_state evaluateBox(int index, NamedBox& box, std::string& aux_word, std::vector<std::string>& new_qrs);
    bool box_inside_nbd(NamedBox& box, std::string& var_word);
	bool box_inside_at_least_two_nbd(NamedBox& box, std::vector<std::string>& var_words); 
//	bool valid_intersection(NamedBox& box);
	bool valid_variety(std::string word, Params<ACJ>& params); 
	bool valid_identity_cyclic(std::string word, Params<ACJ>& params);
	const char* getName(int index);
	int add(std::string word);
	void load(const char* fileName);
	void loadImpossibleRelations(const char* fileName);
	SL2ACJI construct_word(std::string word, Params<ACJ>& params);
	SL2CI construct_word(std::string word, Params<XComplex>& params);
private:
	std::map<std::string, int> stringIndex;
	std::vector<std::string> indexString;
	box_state evaluate_approx(std::string word, Params<XComplex>& params);
    box_state evaluate_ACJ(std::string word, Params<ACJ>& params, std::string& aux_word, std::vector<std::string>& new_qrs);
    bool ready_for_parabolics_test(SL2ACJI& w);
    bool only_bad_parabolics(SL2ACJI& w, Params<ACJ>& params);
//	void enumerate(const char* w);
//	void enumerateTails(std::string s, int pCount, int lCount);
	ImpossibleRelations *impossible;
};


// TODO : Check proof
inline const bool maybe_variety(const SL2CI& w) {
    return (absUB(w.c) < 1) && (absUB(w.b) < 1);
}

inline const bool inside_var_nbd(const SL2ACJI& w)
{
    return (absUB(w.c) < 1) && (absUB(w.b) < 1);
}

inline const bool not_para_fix_inf(const SL2ACJI&x) {
    return x.inv || absLB(x.c) > 0 
                 || ((absLB(x.a-1) > 0 || absLB(x.d-1) > 0) && (absLB(x.a+1) > 0 || absLB(x.d+1) > 0));
}

inline const bool not_identity(const SL2ACJI&x) {
    return absLB(x.b) > 0 || not_para_fix_inf(x);
}

// TODO : Do we need this?
inline const bool not_zero(const SL2ACJI&x) {
    return absLB(x.a) > 0 || absLB(x.b) > 0 || absLB(x.c) > 0 || absLB(x.d) > 0;
}

inline const bool maybe_large_horoball(const SL2CI& w, const Params<XComplex>& params) {
    return absUB((w.c / params.loxodromic_sqrt).z) < 1;
}

inline bool large_horoball(SL2ACJI& w, const Params<ACJ>& params) {
    return absUB(w.c / params.loxodromic_sqrt) < 1;
}
