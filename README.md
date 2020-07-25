# Caesar-Cipher
C implementation of Caesar's Cipher

<p>Supposedly, Caesar (yes, that Caesar) used to “encrypt” (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places.</p>

<p>The secrecy of this “cryptosystem” relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters (e.g., 1). Not particularly secure by modern standards, but, hey, if you’re perhaps the first in the world to do it, pretty secure!</p>

<p>Unencrypted text is generally called <em>plaintext</em>. Encrypted text is generally called <em>ciphertext</em>. And the secret used is called a <em>key</em>.</p>

<p>To be clear, then, here’s how encrypting <code class="highlighter-rouge">HELLO</code> with a key of 1 yields <code class="highlighter-rouge">IFMMP</code>:</p>

<table>
  <thead>
    <tr>
      <th>plaintext</th>
      <th>H</th>
      <th>E</th>
      <th>L</th>
      <th>L</th>
      <th>O</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>+ key</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
    </tr>
    <tr>
      <td>= ciphertext</td>
      <td>I</td>
      <td>F</td>
      <td>M</td>
      <td>M</td>
      <td>P</td>
    </tr>
  </tbody>
</table>

<p>More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by <em>k</em> positions. More formally, if <em>p</em> is some plaintext (i.e., an unencrypted message), <em>p<sub>i</sub></em> is the <em>i<sup>th</sup></em> character in <em>p</em>, and <em>k</em> is a secret key (i.e., a non-negative integer), then each letter, <em>c<sub>i</sub></em>, in the ciphertext, <em>c</em>, is computed as</p>

<p>c<sub>i</sub> = (p<sub>i</sub> + k) % 26</p>

<p>wherein <code class="highlighter-rouge">% 26</code> here means “remainder when dividing by 26.” This formula perhaps makes the cipher seem more complicated than it is, but it’s really just a concise way of expressing the algorithm precisely. Indeed, for the sake of discussion, think of A (or a) as 0, B (or b) as 1, …, H (or h) as 7, I (or i) as 8, …, and Z (or z) as 25. Suppose that Caesar just wants to say Hi to someone confidentially using, this time, a key, <em>k</em>, of 3. And so his plaintext, <em>p</em>, is Hi, in which case his plaintext’s first character, <em>p<sub>0</sub></em>, is H (aka 7), and his plaintext’s second character, <em>p<sub>1</sub></em>, is i (aka 8). His ciphertext’s first character, <em>c<sub>0</sub></em>, is thus K, and his ciphertext’s second character, <em>c<sub>1</sub></em>, is thus L. Can you see why?</p>
