class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long long sumSkill = accumulate(skill.begin(), skill.end(), 0LL);
        long long prevWizardDone = sumSkill * mana[0];
        int m = mana.size(), n = skill.size();

        for (int j = 1; j < m; ++j) {
            long long prevPotionDone = prevWizardDone;
            for (int i = n - 2; i >= 0; --i) {
                prevPotionDone -= (long long)skill[i + 1] * mana[j - 1];
                prevWizardDone = max(prevPotionDone,
                                     prevWizardDone - (long long)skill[i] * mana[j]);
            }
            prevWizardDone += sumSkill * mana[j];
            }

        return prevWizardDone;

    }
};