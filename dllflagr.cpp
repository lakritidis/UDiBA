#include "flagr.cpp"

/// ////////////////////////////////////////////////////////////////////////////////////////////////
/// FLAGR exposed C functions - Dynamic Library References
/// C functions that i) wrap around the corresponding C++ functions and ii) are exposed to DLL.
extern "C" {
	/// Wrapper for CombSUM/CombMNZ
	__declspec(dllexport) void __cdecl Linear(const char inf[], const char relf[], const int evpts, const int ram, const char ranstr[], const char out[]) {

		struct UserParams uParams;
		srand(time(0));

		uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
		strcpy(uParams.input_file, inf);

		uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
		strcpy(uParams.random_string, ranstr);

		uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
		strcpy(uParams.output_dir, out);

		if (strlen(relf) > 0) {
			uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
			strcpy(uParams.rels_file, relf);
		} else {
			uParams.rels_file = NULL;
		}

		uParams.eval_points = evpts;
		uParams.rank_aggregation_method = ram;

		FLAGR_DRIVER(uParams);

		if (uParams.input_file) free(uParams.input_file);
		if (uParams.rels_file) free(uParams.rels_file);
		if (uParams.rels_file) free(uParams.random_string);
		if (uParams.output_dir) free(uParams.output_dir);
	}

	/// Wrapper for the Condorcet Winners Method
	__declspec(dllexport) void __cdecl Condorcet(const char inf[], const char relf[], const int evpts, const char ranstr[], const char out[]) {

		struct UserParams uParams;
		srand(time(0));

		uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
		strcpy(uParams.input_file, inf);

		uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
		strcpy(uParams.random_string, ranstr);

		uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
		strcpy(uParams.output_dir, out);

		if (strlen(relf) > 0) {
			uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
			strcpy(uParams.rels_file, relf);
		} else {
			uParams.rels_file = NULL;
		}

		uParams.eval_points = evpts;
		uParams.rank_aggregation_method = 200;

		FLAGR_DRIVER(uParams);

		if (uParams.input_file) free(uParams.input_file);
		if (uParams.rels_file) free(uParams.rels_file);
		if (uParams.rels_file) free(uParams.random_string);
		if (uParams.output_dir) free(uParams.output_dir);
	}

	/// Wrapper for the Copeland Winners Method
	__declspec(dllexport) void __cdecl Copeland(const char inf[], const char relf[], const int evpts, const char ranstr[], const char out[]) {

		struct UserParams uParams;
		srand(time(0));

		uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
		strcpy(uParams.input_file, inf);

		uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
		strcpy(uParams.random_string, ranstr);

		uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
		strcpy(uParams.output_dir, out);

		if (strlen(relf) > 0) {
			uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
			strcpy(uParams.rels_file, relf);
		} else {
			uParams.rels_file = NULL;
		}

		uParams.eval_points = evpts;
		uParams.rank_aggregation_method = 201;

		FLAGR_DRIVER(uParams);

		if (uParams.input_file) free(uParams.input_file);
		if (uParams.rels_file) free(uParams.rels_file);
		if (uParams.rels_file) free(uParams.random_string);
		if (uParams.output_dir) free(uParams.output_dir);
	}

	/// Wrapper for the Outranking Approach of Farah and Vanderpooten [2]
	__declspec(dllexport) void __cdecl OutrankingApproach
		(const char inf[], const char relf[], const int evpts, const char ranstr[], const char out[],
			const float pref_t, const float veto_t, const float conc_t, const float disc_t) {

				struct UserParams uParams;
				srand(time(0));

				uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
				strcpy(uParams.input_file, inf);

				uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
				strcpy(uParams.random_string, ranstr);

				uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
				strcpy(uParams.output_dir, out);

				if (strlen(relf) > 0) {
					uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
					strcpy(uParams.rels_file, relf);
				} else {
					uParams.rels_file = NULL;
				}

				uParams.eval_points = evpts;
				uParams.rank_aggregation_method = 300;
				uParams.pref_thr = pref_t;
				uParams.veto_thr = veto_t;
				uParams.conc_thr = conc_t;
				uParams.disc_thr = disc_t;

				FLAGR_DRIVER(uParams);

				if (uParams.input_file) free(uParams.input_file);
				if (uParams.rels_file) free(uParams.rels_file);
				if (uParams.rels_file) free(uParams.random_string);
				if (uParams.output_dir) free(uParams.output_dir);
	}

	/// Wrapper for Kemeny Optimal Aggregation (brute force implementation)
	__declspec(dllexport) void __cdecl Kemeny(const char inf[], const char relf[], const int evpts, const char ranstr[], const char out[]) {

		struct UserParams uParams;
		srand(time(0));

		uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
		strcpy(uParams.input_file, inf);

		uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
		strcpy(uParams.random_string, ranstr);

		uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
		strcpy(uParams.output_dir, out);

		if (strlen(relf) > 0) {
			uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
			strcpy(uParams.rels_file, relf);
		} else {
			uParams.rels_file = NULL;
		}

		uParams.eval_points = evpts;
		uParams.rank_aggregation_method = 400;

		FLAGR_DRIVER(uParams);

		if (uParams.input_file) free(uParams.input_file);
		if (uParams.rels_file) free(uParams.rels_file);
		if (uParams.rels_file) free(uParams.random_string);
		if (uParams.output_dir) free(uParams.output_dir);
	}

	/// Wrapper for Robust Rank Aggregation of Kolde et. al, 2012 [7]
	__declspec(dllexport) void __cdecl RobustRA
		(const char inf[], const char relf[], const int evpts, const char ranstr[], const char out[],
		const bool exact) {

			struct UserParams uParams;
			srand(time(0));

			uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
			strcpy(uParams.input_file, inf);

			uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
			strcpy(uParams.random_string, ranstr);

			uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
			strcpy(uParams.output_dir, out);

			if (strlen(relf) > 0) {
				uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
				strcpy(uParams.rels_file, relf);
			} else {
				uParams.rels_file = NULL;
			}

			uParams.eval_points = evpts;
			uParams.exact = exact;
			uParams.rank_aggregation_method = 401;

			FLAGR_DRIVER(uParams);

			if (uParams.input_file) free(uParams.input_file);
			if (uParams.rels_file) free(uParams.rels_file);
			if (uParams.rels_file) free(uParams.random_string);
			if (uParams.output_dir) free(uParams.output_dir);
	}

	/// Wrapper the distance-based iterative rank aggregation method of Akritidis et. al [5] - DIBRA
	__declspec(dllexport) void __cdecl DIBRA
		(const char inf[], const char relf[], const int evpts, const int agg, const char ranstr[],
			const char out[], const int wnorm, const int dist, const bool prune, const float gamma,
			const float d1, const float d2, const float tol, const int iter,
			const float pref_t, const float veto_t, const float conc_t, const float disc_t) {

				struct UserParams uParams;
				srand(time(0));

				uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
				strcpy(uParams.input_file, inf);

				uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
				strcpy(uParams.random_string, ranstr);

				uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
				strcpy(uParams.output_dir, out);

				if (strlen(relf) > 0) {
					uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
					strcpy(uParams.rels_file, relf);
				} else {
					uParams.rels_file = NULL;
				}

				uParams.eval_points = evpts;
				uParams.rank_aggregation_method = agg;
				uParams.weight_normalization = wnorm;
				uParams.distance = dist;
				uParams.prune = prune;
				uParams.gamma = gamma;
				uParams.delta1 = d1;
				uParams.delta2 = d2;
				uParams.tol = tol;
				uParams.max_iter = iter;
				uParams.pref_thr = pref_t;
				uParams.veto_thr = veto_t;
				uParams.conc_thr = conc_t;
				uParams.disc_thr = disc_t;

				FLAGR_DRIVER(uParams);

				if (uParams.input_file) free(uParams.input_file);
				if (uParams.rels_file) free(uParams.rels_file);
				if (uParams.rels_file) free(uParams.random_string);
				if (uParams.output_dir) free(uParams.output_dir);
	}

	/// Wrapper the preference relation rank aggregation method of Desarkar et. al, 2016 [3]
	__declspec(dllexport) void __cdecl PrefRel(const char inf[], const char relf[], const int evpts, const char ranstr[],
				const char out[], const float alpha, const float beta) {

				struct UserParams uParams;
				srand(time(0));

				uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
				strcpy(uParams.input_file, inf);

				uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
				strcpy(uParams.random_string, ranstr);

				uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
				strcpy(uParams.output_dir, out);

				if (strlen(relf) > 0) {
					uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
					strcpy(uParams.rels_file, relf);
				} else {
					uParams.rels_file = NULL;
				}

				uParams.eval_points = evpts;
				uParams.rank_aggregation_method = 600;
				uParams.alpha = alpha;
				uParams.beta = beta;

				FLAGR_DRIVER(uParams);

				if (uParams.input_file) free(uParams.input_file);
				if (uParams.rels_file) free(uParams.rels_file);
				if (uParams.rels_file) free(uParams.random_string);
				if (uParams.output_dir) free(uParams.output_dir);
	}

	/// Wrapper for Agglomerative rank aggregation method of Chatterjee et. al, 2018 [4]
	__declspec(dllexport) void __cdecl Agglomerative(const char inf[], const char relf[], const int evpts, const char ranstr[],
				const char out[], const float c1, const float c2) {

				struct UserParams uParams;
				srand(time(0));

				uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
				strcpy(uParams.input_file, inf);

				uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
				strcpy(uParams.random_string, ranstr);

				uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
				strcpy(uParams.output_dir, out);

				if (strlen(relf) > 0) {
					uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
					strcpy(uParams.rels_file, relf);
				} else {
					uParams.rels_file = NULL;
				}

				uParams.eval_points = evpts;
				uParams.rank_aggregation_method = 700;
				uParams.c1 = c1;
				uParams.c2 = c2;

				FLAGR_DRIVER(uParams);

				if (uParams.input_file) free(uParams.input_file);
				if (uParams.rels_file) free(uParams.rels_file);
				if (uParams.rels_file) free(uParams.random_string);
				if (uParams.output_dir) free(uParams.output_dir);
	}

	/// Wrapper for the Markov Chains methods of Dwork et. al, 2001 [6]
	__declspec(dllexport) void __cdecl MC(const char inf[], const char relf[], const int evpts, const int ram, const char ranstr[],
			const char out[], const float ergodic_number, const float delta, const int iter) {

				struct UserParams uParams;
				srand(time(0));

				uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
				strcpy(uParams.input_file, inf);

				uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
				strcpy(uParams.random_string, ranstr);

				uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
				strcpy(uParams.output_dir, out);

				if (strlen(relf) > 0) {
					uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
					strcpy(uParams.rels_file, relf);
				} else {
					uParams.rels_file = NULL;
				}

				uParams.eval_points = evpts;
				uParams.rank_aggregation_method = ram;
				uParams.alpha = ergodic_number;
				uParams.delta1 = delta;
				uParams.max_iter = iter;

				FLAGR_DRIVER(uParams);

				if (uParams.input_file) free(uParams.input_file);
				if (uParams.rels_file) free(uParams.rels_file);
				if (uParams.rels_file) free(uParams.random_string);
				if (uParams.output_dir) free(uParams.output_dir);
	}

	/// Wrapper for the first custom method
	__declspec(dllexport) void __cdecl Custom1(const char inf[], const char relf[], const int evpts, const char ranstr[], const char out[]) {

		struct UserParams uParams;
		srand(time(0));

		uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
		strcpy(uParams.input_file, inf);

		uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
		strcpy(uParams.random_string, ranstr);

		uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
		strcpy(uParams.output_dir, out);

		if (strlen(relf) > 0) {
			uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
			strcpy(uParams.rels_file, relf);
		} else {
			uParams.rels_file = NULL;
		}

		uParams.eval_points = evpts;
		uParams.rank_aggregation_method = 901;

		FLAGR_DRIVER(uParams);

		if (uParams.input_file) free(uParams.input_file);
		if (uParams.rels_file) free(uParams.rels_file);
		if (uParams.rels_file) free(uParams.random_string);
		if (uParams.output_dir) free(uParams.output_dir);
	}

	/// Wrapper for the second custom method
	__declspec(dllexport) void __cdecl Custom2(const char inf[], const char relf[], const int evpts, const char ranstr[], const char out[]) {

		struct UserParams uParams;
		srand(time(0));

		uParams.input_file = (char *)malloc((strlen(inf) + 1) * sizeof(char));
		strcpy(uParams.input_file, inf);

		uParams.random_string = (char *)malloc((strlen(ranstr) + 1) * sizeof(char));
		strcpy(uParams.random_string, ranstr);

		uParams.output_dir = (char *)malloc((strlen(out) + 1) * sizeof(char));
		strcpy(uParams.output_dir, out);

		if (strlen(relf) > 0) {
			uParams.rels_file = (char *)malloc((strlen(relf) + 1) * sizeof(char));
			strcpy(uParams.rels_file, relf);
		} else {
			uParams.rels_file = NULL;
		}

		uParams.eval_points = evpts;
		uParams.rank_aggregation_method = 902;

		FLAGR_DRIVER(uParams);

		if (uParams.input_file) free(uParams.input_file);
		if (uParams.rels_file) free(uParams.rels_file);
		if (uParams.rels_file) free(uParams.random_string);
		if (uParams.output_dir) free(uParams.output_dir);
	}

}

/// ///////////////////////////////////////////////////////////////////////////////////////////////
/// Main
int main(int argc, char *argv[]) {
	char input_file[] = "/media/leo/B65266EC5266B133/phd_Research/08 - Datasets/TREC/Synthetic/MOSO.csv";
//	char input_file[] = "/media/leo/B65266EC5266B133/phd_Research/08 - Datasets/TREC/Synthetic/cellCycleKO.csv";
	char qrels_file[] = "/media/leo/B65266EC5266B133/phd_Research/08 - Datasets/TREC/Synthetic/MOSO_qrels.csv";
	char output_dir[] = "/tmp";

	Linear(input_file, qrels_file, 20, 100, "Linear_out", output_dir);

	Condorcet(input_file, qrels_file, 20, "Condorcet_out", output_dir);

	Copeland(input_file, qrels_file, 20, "Copeland_out", output_dir);

	OutrankingApproach(input_file, qrels_file, 20, "Outrank_out", output_dir, 0.0, 0.75, 0.0, 0.25);

	DIBRA(input_file, qrels_file, 20, 5101, "DIBRA_out", output_dir,
		2, 3, true, 1.5, 0.4, 0.1, 0.01, 50, 0.0, 0.75, 0.0, 0.25);

	PrefRel(input_file, qrels_file, 20, "PrefRel_out", output_dir, 0.1, 0.5);

	Agglomerative(input_file, qrels_file, 20, "Agglomerative_out", output_dir, 2.5, 1.5);

	MC(input_file, qrels_file, 20, 804, "MC_out", output_dir, 0.15, 0.00000001, 200);

//	Kemeny(input_file, qrels_file, 20, "Kemeny_out", output_dir);

	RobustRA(input_file, qrels_file, 20, "RRA", output_dir, false);

	Custom1(input_file, qrels_file, 20, "RRA", output_dir);

	Custom2(input_file, qrels_file, 20, "RRA", output_dir);

	return 0;
}
